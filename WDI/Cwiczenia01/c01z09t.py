import math

n = int(input())

print(1)

for i in range (2,int(math.sqrt(n))+1) :
    if n%i == 0 :
        print(i)
        print(int(n/i))

print(n)


