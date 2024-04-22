#include "../include/arithmetic.h"

int perform_arithmetic(int x, char op, int y) {
    switch (op) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            if (y != 0) {
                return x / y;
            } else {
                // Division by zero error
                return 0;
            }
        default:
            // Invalid operator
            return 0;
    }
}