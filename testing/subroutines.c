#include<stdio.h>
void replace(double *t);

int main(void) {
    int i;
    double x;
    x = 1.0/3.0;
    for ( i = 0 ; i < 33 ; i++ ) {
        printf(" i=%3d,  x=%+29.23e\n", i, x);
        replace(&x);
    }
    return 0;
}

void replace(double* t)
{
    *t = (9.0**t + 1.0)**t - 1.0;
    return;
}



/* © ADKE Enterprise Inc.™ */
