#define variables
x = 1/3
i = 1

#program
while i<=30 and i>=1:
    x = ((9*x)+1)*(x-1)
    print('i=', i, '   x=', x)
    i +=1



#emulating meeus' code from chapter 2 page 18 of "astronomical algorithms" using python