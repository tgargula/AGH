# Quick sort algorithm
#
# DESCRIPTION
# Quicksort is a divide-and-conquer algorithm. It works by selecting a 'pivot' element from the array
# and partitioning the other elements into two sub-arrays, according to whether they are less than or
# greater than the pivot. The sub-arrays are then sorted recursively.
# The 'pivot' can be chosen in many ways. I could be e.g. the first, the middle or the last element.
# By choosing the last element as the pivot we spare one swap operation each instance.
# 
# COMPLEXITY
# Average time complexity:  O(n log n)
# Pessimistic time complexity: O(n^2)
# Space complexity: *depends on the implementation*
# This one has space complexity O(1)

from random import randint

def rand_partition(A, p, r):
    j = randint(p, r)
    A[j], A[r] = A[r], A[j]
    return partition(A, p, r)

def partition(A, p, r):
    j = p
    for i in range(p, r):
        if A[i] < A[r]:
            A[i], A[j] = A[j], A[i]    
            j += 1
    A[j], A[r] = A[r], A[j]
    return j

def quick_sort(A, p, r):
    if p < r:
        q = rand_partition(A, p, r)
        quick_sort(A, p, q-1)
        quick_sort(A, q+1, r)

A = [324,34,4523,4,53,23,4,3,423]
quick_sort(A, 0, len(A)-1)
print(A)