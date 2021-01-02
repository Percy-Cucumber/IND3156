#import
import random

#code
random.seed(42)
total=1000000*1000
out = 0
for i in range(total):
    x = random.random()
    y = random.random()
    if x*x+y*y > 1:
        out = out + 1
print( 4.0*(1.0-float(out)/float(total)))



#got help from Natalie Silva