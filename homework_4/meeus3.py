#import
import time
start_time = time.time()

#define variables
i = 0

#program
while i >= 0 and i <= 100:
    u = i
#    print("u=", u)         #when results are printed as u=# instead of # it outputs a value of 99.9999999999986 instead of 100.0 (which is what Meeus was checking for with this program)
    print(u)
    i += 0.1

#end
print "My program took", time.time() - start_time, "to run"



#this python code is based on meeus' code in on the bottom of page 19 in the second chapter of astronomical algorithms
#https://stackoverflow.com/questions/12444004/how-long-does-my-python-application-take-to-run?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa