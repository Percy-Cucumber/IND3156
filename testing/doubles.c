#include<stdio.h>
int main(void) {
    double* replace(double input1, double input2);
    double* p;
    double x, denom;
    
    denom = 3.0;
    x = 1.0/denom;
    printf("\n the two memory addresses are %p and %p \n\n", &x, &denom);
    printf("\n x and denom before operation: %+26.23f, %.1f\n", x, denom);
    p = replace(x, denom);
    printf("  x and denom after operation: %+26.23f, %.1f\n\n", *p, *(p+1));
    printf("\n the two memory addresses are %p and %p \n\n", p, p+1);           //p+1 -> go to the next address
    
    return 0;
}

double* replace(double input1, double input2) {
    static double output[2];            //static means it gets written in static memory (memory that does not get overwritten)
    output[0] = (input2*input2*input1 + 1.0)*input1 - 1.0;
    output[1] = input2*42.0;
    return output;
}
