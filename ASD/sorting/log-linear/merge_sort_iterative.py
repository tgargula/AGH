# Merge sort algorithm
#
# This merge sort uses naturally sorted fragments and merges each of two following fragments
# It is done iteratively

def next_fragment(A, i):
    j = i+1
    while j < len(A) and A[j-1] <= A[j]: j += 1
    return A[i:j]

def merge(B, C):
    i = j = k = 0
    M = [None] * (len(B) + len(C))
    while i < len(B) and j < len(C):
        if B[i] < C[j]:
            M[k] = B[i]
            i += 1
        else:
            M[k] = C[j]
            j += 1
        k += 1
    while i < len(B):
        M[k] = B[i]
        i += 1
        k += 1
    while j < len(C):
        M[k] = C[j]
        j += 1
        k += 1
    return M

def merge_sort(A):
    while True:
        i = 0
        while i < len(A):
            start = i
            B = next_fragment(A, i)
            i += len(B)
            C = next_fragment(A, i)
            i += len(C)
            M = merge(B, C)
            for j in range(i-start): A[j+start] = M[j]
        if len(C) == 0: break


A = [1,2,31,4,6,321,2,3,43,2,2,3]
merge_sort(A)
print(A)