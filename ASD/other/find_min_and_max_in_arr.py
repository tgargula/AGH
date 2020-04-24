# Find the smallest and the largest number in array in using 3/2*n comparisons
# Solution:
# compare 0. vs 1., 2. vs 3., ... and compare smaller with min and larger with max

inf = float('Inf')

def find_max_and_min(A, m = inf, M = -inf):
    n = len(A)
    if(n % 2 == 0):
        for i in range(0, n, 2):
            if(A[i] > A[i+1]):
                if(M < A[i]): M = A[i]
                if(m > A[i+1]): m = A[i+1]
            else:
                if(M < A[i+1]): M = A[i+1]
                if(m > A[i]): m = A[i]
    else:
        for i in range(0, n - 1, 2):
            if(A[i] > A[i+1]):
                if(M < A[i]): M = A[i]
                if(m > A[i+1]): m = A[i+1]
            else:
                if(M < A[i+1]): M = A[i+1]
                if(m > A[i]): m = A[i]
        if(M < A[n-1]): M = A[n-1]
        if(m > A[n-1]): m = A[n-1]
    return m, M

################

A = [1,2,4,776,356,2543,7694635676,5324,5345,5347,897,24,-11635465431]
print(find_max_and_min(A))