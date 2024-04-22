#include "../include/condition.h"
#include <string.h>

bool evaluate_condition(int x, char *op, int y) {
    int result = 0;
    if(!strcmp(op,">")){
        if(x>y) result = 1;
    }
    else if(!strcmp(op,"<")){
        result = (x < y);
    }
    else if(!strcmp(op,"==")){
        result = (x == y);
    }
    else if(!strcmp(op,">=")){
        result = (x >= y);
    }
    else if(!strcmp(op,"<=")){
        result = (x <= y);
    }
    else if(!strcmp(op,"!=")){
        result = (x != y);
    }
    return result;
}