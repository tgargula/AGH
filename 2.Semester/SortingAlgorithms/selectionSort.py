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
# Time complexity: O(n^2)
# Space complexity: O(1)

def selectionSort (tab):
    N = len(tab)
    indeks = 0
    for i in range(N-1):
        indeks = i
        mini = tab[i]
        acct = tab[i]
        for j in range (i+1, N):
            if tab[j] < mini:
                mini = tab[j]
                indeks = j
            if j == N-1 and mini != indeks:
                tab[i] = mini
                tab[indeks] = acct
    return tab


size = int(input())
t = []

for i in range(size):
    t.append(int(input()))

tab = selectionSort(t)

print(tab)