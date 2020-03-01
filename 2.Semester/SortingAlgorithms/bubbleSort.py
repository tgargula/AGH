def bubbleSort (tab) :
    N = len (tab)
    isSorted = False
    while not isSorted :
        isSorted = True
        for i in range(N-1) :
            if tab[i] > tab[i+1] :
                tab[i], tab[i+1] = tab[i+1], tab[i]
                isSorted = False

table = [1,43,43,32,5,4,3,6,5,32,534,6,7,54,34,34]

print (table)

bubbleSort (table)

print (table)
