// import
#include <stdio.h>
#include <stdlib.h>

// define
#define sqr2(x) ((x)*(x))
#define frand() ((double) rand() / (RAND_MAX))
#define MAXLEN 1000000000

// code
int circumscribed(int radius){
    double xcoord = frand();
    double ycoord = frand();
    double coord = sqr2(xcoord) + sqr2(ycoord);
    
    if(coord <= radius)
        return 1;
    return -1;
}

int main()
{
    int i;
    double circles = 0, rect = 0;;
    for(i = 0; i < MAXLEN; i++)
    {
        if(circumscribed(1) > 0)   		/* got code outline from https://stackoverflow.com/questions/17659652/calculating-pi-using-monte-carlo-method-gives-imprecise-answer */
            circles++;
        rect++;
    }
    
    double PI = (double)4 * circles / rect;
    printf("PI is %2.4f: \n", PI);
    return 0;
}

// end



// recieved help from Aria Druker