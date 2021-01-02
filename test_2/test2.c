#include<stdio.h>
#include<string.h>
int main(void) {
 int a[] = {6,5,4};
 int b[2];

 a[1] = 8;
 printf("\n a[0] = %d\n",a[0]);
 printf("\n a[1] = %d\n",a[1]);
 printf("\n a[2] = %d\n\n",a[2]);
 printf("\n b[0] = %d\n",b[0]);
 printf("\n b[1] = %d\n",b[1]);
 printf("\n b[2] = %d\n\n",b[2]);
 return 0;
}