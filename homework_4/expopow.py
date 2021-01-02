#import
import time
start_time = time.time()

#define variables
i = 0

#program
while i >= 0 and i <= 100000000:
    x = 1.1
    x = x**2
    i += 1

#end
print "expopow took", time.time() - start_time, "to run"


#emulating Ian Hoffman's expopow.c code in python
#referenced https://www.digitalocean.com/community/tutorials/how-to-do-math-in-python-3-with-operators and https://stackoverflow.com/questions/12444004/how-long-does-my-python-application-take-to-run?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa