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
    def findMaxNumber(inputList):
        maxNumber = 0
        for i in range(len(inputList)):
            if maxNumber < inputList[i]:
                maxNumber = inputList[i]
        return maxNumber

    maxNumber = findMaxNumber(inputList)
    sortedList = [None]*(len(inputList)-1)
    tempList = [0]*maxNumber
    
    for j in range (len(inputList)):
        tempList[inputList[j]] += 1
    
    for i in range (1, maxNumber+1):
        tempList[i] += tempList[i-1]
    
    for j in range (len(inputList)):
        sortedList[tempList[inputList[j]]-1] = inputList[j]
        tempList[inputList[j]] -= 1
    
    return sortedList


L = [3,5,2,29,7,5,7,5,5,5]

print(L)

L = countingSort(L)

print(L)