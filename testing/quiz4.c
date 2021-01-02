#include<stdio.h>
int main(void) {
    double replace(double input1, double input2);
    double x, denom;
    
    denom = 3.0;
    x = 1.0/denom;
    printf("\n x and denom before operation: %+26.23f, %.1f\n",x, denom);
    x = replace(x, denom);
    printf("  x and denom after operation: %+26.23f, %.1f\n\n",x, denom);
    
    return 0;
}

double replace(double input1, double input2) {
    input1 = (input2*input2* input1 + 1.0)* input1 - 1.0;
    input2 = input2*42.0;
    return input1;
}


/* © ADKE Enterprise Inc.™ */
