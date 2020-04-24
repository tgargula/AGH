# Counting sort algorithm
#
# DESCRIPTION
# It is an integer sorting algorithm that operates by counting numbers of objects that have
# each distinct value
#
# COMPLEXITY
# Time complexity:  O(n+k)
# Space complexity: O(n+k)
#                           where k is the maximum number in the list

def counting_sort(A):
    n = len(A)
    k = max(A) + 1
    B = [0]*k
    C = [None]*n
    for i in range(n): B[A[i]] += 1
    for i in range(1,k): B[i] += B[i-1]
    for i in range(n):
        B[A[i]] -= 1
        C[B[A[i]]] = A[i]
    for i in range(n): A[i] = C[i]

A = [1,4,3,2,5,4]
counting_sort(A)
print(A)