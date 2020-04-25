# Quick sort algorithm – iterative version (stack)
#
# DESCRIPTION
# Quicksort is a divide-and-conquer algorithm. It works by selecting a pivot (q) element from the array
# and partitioning the other elements into two sub-arrays, according to whether they are less than or
# greater than the pivot. The sub-arrays are then sorted recursively.
# The pivot can be chosen in many ways. I could be e.g. the first, the middle or the last element.
# By choosing the last element as the pivot we spare one swap operation each instance.
# 
# COMPLEXITY
# Average time complexity:  O(n log n)
# Pessimistic time complexity: O(n^2)
# Space complexity: O(n)
# This one has space complexity O(1)

from random import randint

def partition(L, p, r):
    x = L[r]
    i = p-1
    for j in range(p, r):
        if L[j] <= x:
            i += 1
            L[i], L[j] = L[j], L[i]
    L[i+1], L[r] = L[r], L[i+1]
    return i+1

def rand_partition (L, p, r):
    j = randint(p, r)
    L[j], L[r] = L[r], L[j]
    return partition(L,p,r)

def empty(top): return top < 0

def pop2(stack, top): return stack[top], stack[top-1]

def push2(stack, top, p, r):
    stack[top+1] = p
    stack[top+2] = r

def quick_sort_iterative(L, p, r):
    size = r - p + 1
    stack = [None] * size
    top = -1
    push2(stack, top, p, r)
    top += 2
    while not empty(top):
        r, p = pop2(stack, top)
        top -= 2
        q = rand_partition(L, p, r)
        if q-1 > p:
            push2(stack, top, p, q-1)
            top += 2
        if q+1 < r:
            push2(stack, top, q+1, r)
            top += 2

L = [3,5,2,10,8,4,7,6,1,9]
print(L)
quick_sort_iterative(L, 0, len(L)-1)
print(L)