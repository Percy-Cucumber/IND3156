#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(int *one, int *two, double *overone, double *overtwo);
void invert(int *one, int *two, double *overone, double *overtwo);
void operate( void(*fp)(int*, int*, double*, double*), int *one, int *two, double *overone, double *overtwo);
void banner(void);

int main(int argc, char *argv[]) {
 int n, m;
 double x, y;
 void (*pfunc)(int*, int*, double*, double*);

 if ( argc != 4 || strlen(argv[1]) != 1 ) {
  banner();
  return 0;
 } else {
  n = atoi(argv[2]);
  x = (double)n;
  m = atoi(argv[3]);
  y = (double)m;
 }

 if ( strcmp(argv[1],"s")==0 ) {
  pfunc = &swap;
 } else if ( strcmp(argv[1],"i")==0 ) {
  pfunc = &invert;
 } else {
  banner();
  return 0;
 }

 printf("\n values before the operation: %.3f, %.3f\n", x, y);
 operate(pfunc,&n,&m,&x,&y);  
 printf("\n  values after the operation: %.3f, %.3f\n\n", x, y);

 return 0;
}

void swap(int *one, int *two, double *overone, double *overtwo) {
 int temp;
 double tmp;
 temp = *one;
 *one = *two;
 *two = temp;
 tmp = *overone;
 *overone = *overtwo;
 *overtwo = tmp;
 return;
}

void invert(int *one, int *two, double *overone, double *overtwo){
 *overone = 1.0/ *overone;
 *overtwo = 1.0/ *overtwo;
 return;
}

void operate( void(*fp)(int*, int*, double*, double*), int *one, int *two, double *overone, double *overtwo) {
 fp(one,two,overone,overtwo);
 return;
}

void banner(void) {
 printf("\n");
 printf(" ################################\n");
 printf(" #  swap or invert ints n & m   #\n");
 printf(" #    usage: a.out {s,i} n m    #\n");
 printf(" ################################\n");
 printf("\n");
}