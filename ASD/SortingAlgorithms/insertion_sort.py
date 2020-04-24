# Insertion sort algorithm
# 
# DESCRIPTION
# It is a simple sorting algorithm that builds the final sorted array (or list) one item at a time.
# 
# COMPLEXITY
# Time complexity:  O(n^2)

def insertion_sort(A):
    for i in range(1, len(A)):
        key = A[i]
        j = i - 1
        while j >= 0 and A[j] > key:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = key
    
A = [1,6,3,9,5,41,23,56]
insertion_sort(A)
print(A)