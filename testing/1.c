#include<stdio.h>
#include<math.h>

int main(void) {
 int j;
 int x;

 x = 2;
 j = 0;
 printf("  j   10's                  x\n");
// while ( x != x + 1 ) {
 while ( j < 60 ) {
  j++;
  x = x * 2.0;
  printf(" %2u  %5.2f %u\n", j, log10(2.0)*(float)j, x);
 }

 return 0;
}