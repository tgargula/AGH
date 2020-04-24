# Cocktail shaker sort algorithm
# 
# DESCRIPTION
# It repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
# It changes direction after reaching the end of the list.
# 
# COMPLEXITY
# Time complexity:  O(n^2)
# Space complexity: O(1)

def cocktail_shaker_sort(A):
    N = len(A)
    start = 0
    end = N-1
    while start < end:
        for i in range(start, end):
            if A[i] > A[i+1]:
                A[i], A[i+1] = A[i+1], A[i]
        for i in range(end, start, -1):
            if A[i] < A[i-1]:
                A[i], A[i-1] = A[i-1], A[i]
        start += 1
        end -= 1

A = [3,5,2,10,8,4,7,6,1,9]
print(A)
cocktail_shaker_sort(A)
print(A)