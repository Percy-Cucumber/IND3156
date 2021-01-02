#include<stdlib.h>
#include<stdio.h>
 
int main(void) {
 int i;
 double x;
 
 srand(42);
 
 x =(double) (rand() / (RAND_MAX + 1.0));
 printf("\n        x = %+18.16f\n\n",x);
 
 return 0;
}