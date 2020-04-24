# Counting sort algorithm
#
# DESCRIPTION
# It is an integer sorting algorithm that operates by counting numbers of objects that have
# each distinct value
#
# COMPLEXITY
# Time complexity:  O(n+k)
# Space complexity: O(n+k)
#                           where k is the maximum number in the list

def countingSort(inputList):

    n = len(inputList)
    maxNumber = max(inputList)
    sortedList = [None]*n
    tempList = [0]*(maxNumber+1)
    
    for j in range (n):
        tempList[inputList[j]] += 1
    
    for i in range (1, maxNumber+1):
        tempList[i] += tempList[i-1]
    
    for j in range (n-1, -1, -1):
        tempList[inputList[j]] -= 1
        sortedList[tempList[inputList[j]]] = inputList[j]
    
    return sortedList


L = [3,5,2,29,7,5,7,5,5,5]

print(L)

L = countingSort(L)

print(L)