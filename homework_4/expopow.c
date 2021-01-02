#include<math.h>
int main(void)
{
  int i;
  double x;
  for ( i=0 ; i < 100000000 ; i++ ) {
    x = 1.1;
    x = pow(x,2);
  }
  return 0;
}



// Ian Hoffman's Code