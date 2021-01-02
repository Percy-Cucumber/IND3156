# Change FUNCTION and define xmin#
# Define: xmin, xmax, ymin, ymax, and nPoints after ./a.out #



#import
import random
import argparse
import math

#code
parser = argparse.ArgumentParser()
parser.add_argument('-f', action="store", dest="xmin", type=float)
parser.add_argument('-f', action="store", dest="xmax", type=float)
parser.add_argument('-f', action="store", dest="ymin", type=float)
parser.add_argument('-f', action="store", dest="ymax", type=float)
parser.add_argument('-i', action="store", dest="total", type=int)

information = parser.parse_args(args)



# ---- FUNCTION ---- #
def function(x):
#    return x*x*x
	return sqrt (1-x*x)



#code cont.
random.seed(42)

i = 0
ini = 0

for i in range(total):
    x =(xmax-xmin)*random.random()+xmin
    y =(ymax-ymin)*random.random()+ymin
    f = function(x)
    if y > 0.0:
        if y < f:
            ini = ini + 1

area = (xmax-xmin)*(ymax-ymin)
res = area*(float(ini)/float(total))

#print
print ' \n       res={:18.16f} \n'.format(res)



#referenced https://docs.python.org/release/1.5.1p1/tut/functions.html and https://docs.python.org/3.3/library/argparse.html#dest
