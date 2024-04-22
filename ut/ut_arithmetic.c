#include <stdio.h>
#include "../include/arithmetic.h"

void main(){
    int x = 8, y = 3;
    printf("Testing Perform arithmetic:\n");
    printf("Testing function with x = 15 and y = 7 for all operators:\n");
    printf("perform_arithmetic(x,'+',y) : %d\n", perform_arithmetic(x,'+',y));
    printf("perform_arithmetic(x,'-',y) : %d\n", perform_arithmetic(x,'-',y));
    printf("perform_arithmetic(x,'*',y) : %d\n", perform_arithmetic(x,'*',y));
    printf("perform_arithmetic(x,'/',y) : %d\n", perform_arithmetic(x,'/',y));
    //printf("perform_arithmetic(x,'%%',y) : %d\n", perform_arithmetic(x,'%',y));
}