n = int(input('n = '))
b = 2

while n > 1 :
    if n %b == 0 :
        print (b, end = ' ')
        n = n // b
    else :
        b += 1
print ()
