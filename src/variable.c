// variable.c

#include "../include/variable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_VARIABLES 20
#define MAX_VAR_NAME_LENGTH 30

// Structure to represent a variable with a name and a value
struct Variable {
    char var_name[MAX_VAR_NAME_LENGTH];
    int value;
};

// Array to store variables
struct Variable var_list[MAX_VARIABLES];

// Counter to keep track of the number of variables
int var_count = 0;

// Function to check if a string is numeric
int is_numeric(const char *var_name) {
    for (int i = 0; i < strlen(var_name); i++) {
        if (!isdigit(var_name[i])) {
            return 0;  // Not numeric
        }
    }
    return 1;  // Numeric
}

// Function to create a new variable with the given token
void create_variable(char *token) {
    if (var_count < MAX_VARIABLES) {
        // Copy the token (variable name) to the variable list
        strcpy(var_list[var_count].var_name, token);
        var_count++;
    } else {
        printf("Error: Maximum number of variables reached.\n");
    }
}

// Function to assign a value to an existing variable
void assign_variable(char *var_name, int value) {
    int variable_found = 0;
    for (int i = 0; i < var_count; i++) {
        if (strcmp(var_name, var_list[i].var_name) == 0) {
            // Assign the value to the variable if found
            var_list[i].value = value;
            variable_found = 1;
            break;
        }
    }
    if (!variable_found) {
        printf("Error: Variable '%s' not found.\n", var_name);
    }
}

// Function to get the value of a variable
int get_variable_value(char *var_name) {
    if (is_numeric(var_name)) {
        return atoi(var_name);  // Convert numeric string to integer
    }
    for (int i = 0; i < var_count; i++) {
        if (strcmp(var_name, var_list[i].var_name) == 0) {
            // Return the value of the variable if found
            return var_list[i].value;
        }
    }
    printf("Error: Variable '%s' not found.\n", var_name);
    return 0;  // Return a default value
}

