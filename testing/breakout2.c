#include<stdio.h>
int main(void)
{
    
    int j, i;
    int *q;
    j = 10;
    q = &j;
    i = *q;
    printf("\nThe memory address of the integer is %p\n", q);
    printf("         The value of the integer is %d\n\n", i);
    return 0;
}



/* © ADKE Enterprise Inc.™ */
