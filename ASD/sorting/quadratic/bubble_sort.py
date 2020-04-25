# Bubble sort algorithm
# 
# DESCRIPTION
# It repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
# The pass through the list is repeated until the list is sorted.
# 
# COMPLEXITY
# Time complexity:  O(n^2)

def bubble_sort(A):
    N = len(A)
    for j in reversed(range(N)):
        for i in range(j):
            if A[i] > A[i+1]:
                A[i], A[i+1] = A[i+1], A[i]

A = [1,43,43,32,5,4,3,6,5,32,534,6,7,54,34,34]
print(A)
bubble_sort(A)
print(A)