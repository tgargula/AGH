import math

def bucketSort (tab):
    
    def insertionSort (A):

        N = len(A)
        for i in range(N):
            key = A[i]
            k = i-1
            while k >= 0 and A[k] > key:
                A[k+1] = A[k]
                k -= 1

            A[k+1] = key
    
    N = 5 # should be propotional to len(tab)
    buckets = [[] for _ in range(N)]
    M = max(tab)

    for num in tab:
        if num == M: bi = N-1
        else: bi = int(num / M * N)
        buckets[bi].append(num)
    
    print (buckets)

    s = 0
    for A in buckets: insertionSort(A)
    
    output = []
    
    for A in buckets:
        for j in range(len(A)):
            output.append(A[j])

    tab[:] = output



tab = [5,3,2.7,10.2, 0, 21.37, 5.3, 15.6, 21.36, 2.1]

bucketSort(tab)

print(tab)
