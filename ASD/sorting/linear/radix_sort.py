# Radix sort algorithm
#
# DESCRIPTION
# It avoids comparison by creating and distributing elements into
# buckets according to their radix. For elements with more than
# one significant digit, this bucketing process is repeated for
# each digit, while preserving the ordering of the prior step,
# until all digits have been considered.
#
# Time complexity: O(w*(n+k))
# Space complexity: O(w+n)
# where w is the number of bits required to store each key

def counting_sort(A, exp):
    n = len(A)
    B = [None]*n
    C = [0]*10
    for i in range (n):
        j = A[i] // exp
        C[j % 10] += 1
    for i in range (1, 10): C[i] += C[i-1]
    for i in reversed(range(n)):
        j = A[i] // exp
        C[j % 10] -= 1
        B[C[j % 10]] = A[i]
    A[:] = B

def radix_sort(A):
    exp = 1
    while max(A) // exp > 0:
        counting_sort(A, exp)
        exp *= 10

A = [4,3,2137,34,43,341,22,2,3]
radix_sort(A)
print(A)