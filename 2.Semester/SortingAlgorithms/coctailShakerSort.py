# Cocktail shaker sort algorithm
# 
# DESCRIPTION
# It repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
# It changes direction after reaching the end of the list.
# 
# COMPLEXITY
# Time complexity:  O(n^2)
# Space complexity: O(1)

def cocktailShakerSort(L):
    N = len(L)
    start = 0
    end = N-1

    while start < end:
        for i in range(start, end):
            if L[i] > L[i+1]:
                L[i], L[i+1] = L[i+1], L[i]
        
        for i in range(end, start, -1):
            if L[i] < L[i-1]:
                L[i], L[i-1] = L[i-1], L[i]

        start += 1
        end -= 1


L = [3,5,2,10,8,4,7,6,1,9]

print(L)

cocktailShakerSort(L)

print(L)
