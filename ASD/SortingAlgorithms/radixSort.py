# Radix sort algorithm
#
# DESCRIPTION
# It avoids comparison by creating and distributing elements into
# buckets according to their radix. For elements with more than
# one significant digit, this bucketing process is repeated for
# each digit, while preserving the ordering of the prior step,
# until all digits have been considered.
#
# Time complexity: O(w*(n+k))
# Space complexity: O(w+n)
# where w is the number of bits required to store each key

def radixSort(tab):
    
    def countingSort(inputList, exp):

        n = len(inputList)
        sortedList = [None]*n
        tempList = [0]*10
        
        for i in range (n):
            index = tab[i] // exp
            tempList [ index % 10 ] += 1
        
        for i in range (1, 10):
            tempList[i] += tempList[i-1]
        
        for i in range (n-1, -1, -1):
            index = tab[i] // exp
            tempList [ index % 10 ] -= 1
            sortedList [ tempList [ index % 10 ] ] = inputList[i]
        
        return sortedList
    
    max1 = max(tab)
    exp = 1

    while max1 // exp > 0:
        tab = countingSort(tab, exp)
        exp *= 10
    
    return tab


tab = [4,3,2137,34,43,341,22,2,3]
tab = radixSort(tab)
print(tab)