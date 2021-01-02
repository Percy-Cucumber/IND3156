import numpy as np
j=0
x=np.float32(1)
while ( x != x+np.float32(1) ):
 x = x * np.float32(2)
 j = j + 1
 print(j, x)