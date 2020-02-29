import math

n = int(input('n = '))
b = 2

while n > 1 and b <= math.sqrt(n) :
    if n %b == 0 :
        print (b, end = ' ')
        n = n // b
    else :
        b += 1

if n > 1 : print(n) 
