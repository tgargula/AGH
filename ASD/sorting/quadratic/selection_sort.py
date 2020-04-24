# Selection sort algorithm
# 
# DESCRIPTION
# The algorithm divides the input list into two parts: a sorted sublist of items which is built up
# from left to right at the front (left) of the list and a sublist of the remaining unsorted items
# that occupy the rest of the list. Initially, the sorted sublist is empty and the unsorted sublist
# is the entire input list. The algorithm proceeds by finding the smallest (or largest, depending
# on sorting order) element in the unsorted sublist, exchanging (swapping) it with the leftmost
# unsorted element (putting it in sorted order), and moving the sublist boundaries one element to the right. 
# 
# COMPLEXITY
# Time complexity:  O(n^2)

def selection_sort(A):
    n = len(A)
    for i in range(n-1):
        m = i
        for j in range(i+1, n):
            if A[j] < A[m]: m = j
        A[i], A[m] = A[m], A[i]

A = [1,4,3,54,34,23,3,56,43,9]
selection_sort(A)
print(A)