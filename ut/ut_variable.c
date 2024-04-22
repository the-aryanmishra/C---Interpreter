#include <stdio.h>
#include "../include/variable.h"

void main(){
    printf("Testing Variable functions:\n");
    printf("Testing create_variable by executing create_variable(\"num\").\n");
    create_variable("num");
    printf("Testing assign_variable by executing assign_variable(\"num\", 7).\n");
    assign_variable("num", 7);
    printf("Testing get_variable_value by executing printf(\"%%d\\n\",get_variable_value(\"num\")).\n");
    printf("Value returned = %d\n",get_variable_value("num"));
    printf("Testing get_variable_value by executing printf(\"%%d\\n\",get_variable_value(\"15\")).\n");
    printf("Value returned = %d\n",get_variable_value("15"));
}