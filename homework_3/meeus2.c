#include<stdio.h>

int main(void) {
 int i;
 double x;
 x = 1.0/3.0;
 for ( i = 0 ; i < 31 ; i++ ) {					// i++ -> "i" gues up by one ever time the cycle goes through
  printf(" i=%3d,  x=%+29.23e\n", i, x);		// print results ("i" is allocated 3 spaces)
  x = (9.0*x + 1.0)*x - 1.0;
 }
 return 0;
}



/* code template stolen from Ian Hoffman */