/* Change PRINT and RETURN Command(s) */
/* Define: xmin, xmax, ymin, ymax, and nPoints after ./a.out */

//import
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<sys/time.h>
#include<math.h>

//intro & define
int main(int argc, char *argv[]) {
 int i, j, arg5;
 double arg1, arg2, arg3, arg4, answer;
 FILE *urandom;
 unsigned int seed;
 double f(double x);
 double monte(double (*fp)(double), double xmin, double xmax, double ymin, double ymax, int nPoints);
 void banner(void);

//random
 urandom = fopen("/dev/urandom","r");
 fread(&seed,sizeof(seed),1,urandom);
 srand(seed);

//code
 banner();
 if ( argc != 6 ) {
  return 1;
 } else {
  if ( (sscanf(argv[1], "%lf", &arg1)!=1)||(sscanf(argv[2], "%lf", &arg2)!=1)||(sscanf(argv[3], "%lf", &arg3)!=1)||(sscanf(argv[4], "%lf", &arg4)!=1)||(sscanf(argv[5], "%d", &arg5)!=1) ){
   printf("check your input types\n");
   return 1;
  }
 }



/* ---- PRINT ---- */

// printf(" %16.8f\n\n",monte(&f,arg1,arg2,arg3,arg4,arg5));
// answer = monte(&f,arg1,arg2,arg3,arg4,arg5);
 printf(" %16.8f\n\n",4.0*answer);
// printf(" %16.8f\n\n",answer*answer);



//return & end previous loop
 return 0;
}

//new return loop
double f(double x) {



/* ---- RETURN ---- */

// return exp(-1.*x*x);
// return x*x*x;
 return sqrt(1.0-x*x);
// return sin(x);



}

//code / math
double monte(double (*f)(double), double xmin, double xmax, double ymin, double ymax, int nPoints) {
 int i, counter, inside, outside;
 double x, y;

 counter = 0;
 inside = 0;
 outside = 0;
 for (i = 0; i < nPoints; i++) {
  x =(double) (xmax-xmin)*(rand() / (RAND_MAX + 1.0)) + xmin;
  y =(double) (ymax-ymin)*(rand() / (RAND_MAX + 1.0)) + ymin;
  if ( 0.0 < y && y <= f(x) ) {
   counter++;
   inside++;
  } else if ( f(x) <= y && y < 0.0 ) {
   counter--;
   inside++;
  } else {
   outside++;
  }
 }
 if ( inside + outside != nPoints ) {
          printf("darts don't add up\n");
          return -1.0E+217;
 }
 return (double) (xmax-xmin)*(ymax-ymin)*(double)counter/(double)nPoints;
}

//print banner
void banner(void) {
 printf("\n");
 printf(" ########################################\n");
 printf(" #        Monte Carlo integrator        #\n");
 printf(" # usage: a xmin xmax ymin ymax nPoints #\n");
 printf(" ########################################\n");
 printf("\n");
 return;
}



/* original code template stolen from Ian Hoffman */
/* help gotten from Julian & Chase */