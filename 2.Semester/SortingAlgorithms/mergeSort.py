# Merge sort algorithm
#
# DESCRIPTION
# First divide the list into the smallest unit (1 element), then compare each element with
# the adjacent list to sort and merge the two adjacent lists. Finally all the elements are
# sorted and merged.
#
# COMPLEXITY
# Time complexity:  O(n log n)
# Space complexity: O(n)

def mergeSort (L, begin, end):
    def merge (L, begin, middlePoint, end):
        i = begin
        j = middlePoint + 1
        k = 0
        tempTab = []
        for l in range (end-begin+1):
            tempTab.append(None)

        while i <= middlePoint and j <= end:
            if L[i] <= L[j]:
                tempTab[k] = L[i]
                i += 1
            else:
                tempTab[k] = L[j]
                j += 1
            k += 1
        
        while i <= middlePoint:
            tempTab[k] = L[i]
            i += 1
            k += 1
        
        while j <= end:
            tempTab[k] = L[j]
            j += 1
            k += 1

        for l in range(end-begin+1):
            L[begin+l] = tempTab[l]

    if begin < end:
        middlePoint = (begin + end) // 2
        mergeSort (L, begin, middlePoint)
        mergeSort (L, middlePoint+1, end)
        merge (L, begin, middlePoint, end)


L = [3,5,2,10,8,4,7,6,1,9]

print(L)

mergeSort(L, 0, len(L)-1)

print(L)