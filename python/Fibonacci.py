#!/usr/bin/env python3

sum = 0
a,b = 1,1
temp = a + b
while (b < 4000000):
    temp = a
    a = b
    b +=temp
    if (b % 2 == 0):
        sum += b   
 
print(sum)

