// define stuff
#include <math.h>
#include <stdio.h>
extern int j, x;
int x = 1;
int j = 0;

// program
int main () {
START: if (x+1 != x) goto LOOP;
	goto END;
	
LOOP: j= j+1;
	x = x*2;
	printf("value of j = %d\n",j);
	printf("value of x = %d\n",x);
	goto START;

END: printf("value of j = %d\n",j); 
	printf("value of x = %d\n",x);

return 0;			
}



/*	Different Version of Code)

#include <stdio.h>
#include <math.h>

extern int x, j;
int main () {
    int x, j;
    x=1;
    j=0;
  
    x= 2*x;
    LOOP:do {
        j = j+1;
        x = x*2;
        printf("value of j : %d \n", j);
        printf("value of x : %d \n", x);
        printf("value of 10s : %f \n", j*log10(2));
    }while(j<131);
    printf("value of j : %d \n", j);
    printf("value of x : %d \n", x);
    printf("value of 10s : %f \n", j*log10(2));
return 0;
}
*/



/* help recieved from https://en.wikibooks.org/wiki/C_Programming/Variables and https://www.tutorialspoint.com/cprogramming/c_while_loop.htm */