# Merge sort algorithm
#
# DESCRIPTION
# First divide the list into the smallest unit (1 element), then compare each element with
# the adjacent list to sort and merge the two adjacent lists. Finally all the elements are
# sorted and merged.
#
# COMPLEXITY
# Time complexity:  O(n log n)
# Space complexity: O(n)

def merge(A, p, q, r):
    n = r - p + 1
    B = [None] * n
    i = 0
    left = p
    right = q + 1
    while left <= q and right <= r:
        if (A[left] > A[right]):
            B[i] = A[right]
            right += 1
        else:
            B[i] = A[left]
            left += 1
        i += 1
    while left <= q:
        B[i] = A[left]
        left += 1
        i += 1
    while right <= r:
        B[i] = A[right]
        right += 1
        i += 1
    for j in range(n): A[j+p] = B[j]

def merge_sort(A, p, r):
    if r - p > 1:
        q = (p + r) // 2
        merge_sort(A, p, q)
        merge_sort(A, q+1, r)
        merge(A, p, q, r)

A = [1,2,423,3,32,3,4,4,23]
merge_sort(A,0,len(A)-1)
print(A)