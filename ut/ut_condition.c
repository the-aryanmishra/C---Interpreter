#include <stdio.h>
#include "../include/condition.h"

void main(){
    printf("Testing evaluate_condition:\n");
    printf("perform_arithmetic(8, \">\", 5) returns %d\n", evaluate_condition(8,">",5));
    printf("perform_arithmetic(8, \"<\", 5) returns %d\n", evaluate_condition(8,"<",5));
    printf("perform_arithmetic(8, \"==\", 5) returns %d\n", evaluate_condition(8,"==",5));
    printf("perform_arithmetic(8, \">=\", 5) returns %d\n", evaluate_condition(8,">=",5));
    printf("perform_arithmetic(8, \"<=\", 5) returns %d\n", evaluate_condition(8,"<=",5));
    printf("perform_arithmetic(8, \"!=\", 5) returns %d\n", evaluate_condition(8,"!=",5));
    printf("perform_arithmetic(8, \"==\", 8) returns %d\n", evaluate_condition(8,"==",8));
    printf("perform_arithmetic(8, \">=\", 8) returns %d\n", evaluate_condition(8,">=",8));
    printf("perform_arithmetic(8, \"<=\", 8) returns %d\n", evaluate_condition(8,"<=",8));
    printf("perform_arithmetic(8, \"!=\", 8) returns %d\n", evaluate_condition(8,"!=",8));
}