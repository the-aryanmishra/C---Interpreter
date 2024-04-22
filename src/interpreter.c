// interpreter.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/interpreter.h"
#include "../include/variable.h"
#include "../include/arithmetic.h"
#include "../include/condition.h"
#include "../include/print.h"

#define MAX_VAR_SIZE 50

char temp[MAX_VAR_SIZE];

// Function to trim leading and trailing spaces from a string
char* trim(char* token) {
    int i = 0;
    for (int k = 0; k < strlen(token); k++) {
        if (token[k] != ' ') {
            temp[i++] = token[k];
        }
    }
    temp[i] = '\0';
    return temp;
}

// Function to execute C-- code
void execute_c_minus_minus(char* code) {
    int isInsideIf = 0;

    // Tokenize the code based on semicolon
    char* nextStatement;
    char* currentStatement = strtok(code, ";");

    while (currentStatement != NULL) {
        isInsideIf = 0;

        if (strstr(currentStatement, "=") != NULL && (strstr(currentStatement, "if") == NULL && strstr(currentStatement, "(") == NULL)) {
            // Variable assignment
            char* equalSign = strstr(currentStatement, "=");
            char* variableName = currentStatement;
            char* expression = equalSign + 1;
            *equalSign = '\0';

            // Check for variable declaration
            if (strstr(variableName, "int ") != NULL) {
                variableName = strstr(variableName, "int ") + 4;
                create_variable(trim(variableName));
            }

            // Check for arithmetic operation
            char* operator = strpbrk(expression, "+-*/");
            int result = 0;

            if (operator != NULL) {
                char operation = *operator;
                char* operand1 = expression;
                char* operand2 = operator + 1;
                *operator = '\0';
                int x = get_variable_value(trim(operand1));
                int y = get_variable_value(trim(operand2));
                result = perform_arithmetic(x, operation, y);
                *operator = operation;
            } else {
                result = get_variable_value(trim(expression));
            }

            // Assign the result to the variable
            assign_variable(trim(variableName), result);
            *equalSign = '=';
        } else if (strstr(currentStatement, "if") != NULL) {
            // Conditional statement
            isInsideIf = 1;
            char* condition = strstr(currentStatement, "(") + 1;
            char* conditionEnd = strstr(currentStatement, ")");
            *conditionEnd = '\0';

            char* operatorLocation = strpbrk(condition, "<>=");
            int operatorLength = 1;

            if (*(operatorLocation + 1) == '=') {
                operatorLength = operatorLength + 1;
            }

            char originalChar = *(operatorLocation + operatorLength);
            *(operatorLocation + operatorLength) = '\0';
            char comparisonOperator[3];
            strcpy(comparisonOperator, operatorLocation);
            *(operatorLocation + operatorLength) = originalChar;

            char firstOperand[MAX_VAR_SIZE];
            *operatorLocation = '\0';
            strcpy(firstOperand, trim(condition));
            *operatorLocation = comparisonOperator[0];

            char secondOperand[MAX_VAR_SIZE];
            strcpy(secondOperand, trim(operatorLocation + operatorLength));

            // Evaluate the condition
            int evaluationResult = evaluate_condition(get_variable_value(firstOperand), comparisonOperator, get_variable_value(secondOperand));

            *conditionEnd = ')';
            char* codeStart = strstr(currentStatement, "{") + 1;
            currentStatement[strlen(currentStatement)] = ';';
            char* codeEnd = strstr(currentStatement, "}");

            if (evaluationResult) {
                *codeEnd = '\0';
                // Execute the code block
                execute_c_minus_minus(codeStart);
                *codeEnd = '}';
            }

            currentStatement = strtok(codeEnd + 1, ";");
        } else if (strstr(currentStatement, "print") != NULL) {
            // Print statement
            char variableToPrint[MAX_VAR_SIZE];
            strcpy(variableToPrint, trim(strstr(currentStatement, "print ") + 6));
            int result = get_variable_value(variableToPrint);
            print_variable(result);
        }

        if (!isInsideIf) {
            currentStatement = strtok(NULL, ";");
        }
    }
}
