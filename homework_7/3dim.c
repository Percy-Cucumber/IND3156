//import
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

//code
int main(void)
{
   int total=1048576*1024;
   double x,y;
   int i,out; 
   double z;
   double area;

   srand(42);
   out=0;
   for ( i=0; i<total; i++) {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      z = x*x+x-y;
      if (z<=1) out++;
      }
   area=(double)out/total;

//print
   printf("the estimate of the area is %f\n",area);
}



/* got help from Natalie and https://rosettacode.org/wiki/Monte_Carlo_methods */