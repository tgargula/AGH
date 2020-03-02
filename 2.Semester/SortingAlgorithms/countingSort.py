def countingSort(inputList):
    def findMaxNumber(inputList):
        maxNumber = 0
        for i in range(len(inputList)):
            if maxNumber < inputList[i]:
                maxNumber = inputList[i]
        return maxNumber

    maxNumber = findMaxNumber(inputList)
    sortedList = [None for i in range(len(inputList))]
    tempList = [0 for i in range(maxNumber)]
    
    for j in range (len(inputList)):
        tempList[inputList[j]-1] = tempList[inputList[j]-1] + 1
    
    for i in range (1, maxNumber):
        tempList[i] += tempList[i-1]
    
    for j in range (len(inputList)):
        sortedList[tempList[inputList[j]-1]-1] = inputList[j]
        tempList[inputList[j]-1] -= 1
    
    return sortedList


L = [3,5,2,11,7,5,7,5,5,5]

print(L)

L = countingSort(L)

print(L)