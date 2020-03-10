# Quick sort algorithm – iterative version
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

def quickSortIterative(L, start, end):
    def randPartition (L, start, end):
        j = randint(start, end)
        L[j], L[end] = L[end], L[j]
        return partition(L,start,end)

    def partition (L, start, end):
        x = L[end]
        i = start-1
        for j in range(start, end):
            if L[j] <= x:
                i += 1
                L[i], L[j] = L[j], L[i]
        L[i+1], L[end] = L[end], L[i+1]
        return i+1

    size = end - start + 1
    stack = [None] * size
    
    top = -1    # position of the actual top in the stack; -1 means that the stack is empty
    
    top += 1
    stack[top] = start
    top += 1
    stack[top] = end

    while top >= 0:
        end = stack[top]
        top -= 1
        start = stack[top]
        top -= 1

        pivot = randPartition(L, start, end)

        if pivot-1 > start:
            top += 1
            stack[top] = start
            top += 1
            stack[top] = pivot-1 
        
        if pivot+1 < end:
            top += 1
            stack[top] = pivot+1
            top += 1
            stack[top] = end



L = [3,5,2,10,8,4,7,6,1,9]

print(L)

quickSortIterative(L, 0, len(L)-1)

print(L)