#include<stdio.h>
double replace(double input);

int main(void) {
    int i;
    double x;
    x = 1.0/3.0;
    for ( i = 0 ; i < 33 ; i++ ) {
        printf(" i=%3d,  x=%+29.23e\n", i, x);
        x = replace(x);
    }
    return 0;
}

double replace(double input) {
    input = (9.0*input + 1.0)*input - 1.0;
    return input;
}


/* © ADKE Enterprise Inc.™ */
