# Comb sort algorithm
#
# DESCRIPTION
# Works similar to bubble sort, but the gap is bigger
#
# Time complexity:  O(n log n) – best case
# Time complexity:  O(n^2) – worst case

DIV = 1.3

def comb_sort(A):
    end = n = len(A)
    while True:
        end = int(end / DIV)
        i = 0; j = end
        while j < n:
            if A[i] < A[j]:
                A[i], A[j] = A[j], A[i]
            i += 1; j += 1
        if end == 1: break
    is_sorted = False
    while not is_sorted:
        is_sorted = True
        for k in range(1, n):
            if A[k-1] > A[k]:
                A[k-1], A[k] = A[k], A[k-1]
                is_sorted = False

A = [1,2,3,2,2,3,21,34,54,3,343,221,23,2]
comb_sort(A)
print(A)