from random import seed, random

size = 100

def createRandomisedArray () :
    array = []
    seed(0)
    for i in range (size) :
        array.append(int(random()*100))
    
    return tuple(array)


def bubbleSort (array) :
    array = list(array)
    for i in range (size-1) :
        for j in range (size-1-i) :
            if array[j] > array[j+1] :
                array[j], array[j+1] = array[j+1], array[j]

    return tuple(array)


def insertionSort (array) :
    array = list(array)
    for i in range (1, size) :
        element = array[i]
        j = i - 1
        while j >= 0 and array[j] > element :
            array[j+1] = array[j]
            j -= 1
        array[j+1] = element
    
    return tuple(array)


def selectionSort (array) :
    def minimumElementPosition(array,i) :
        minimum = 0
        for i in range (1, size-i) :
            if array[i] < array[minimum] :
                minimum = i
        
        return minimum


    array = list(array)
    for i in range (size) :
        minimum = minimumElementPosition(array[i:],i)
        array[minimum+i], array[i] = array[i], array[minimum+i]

    return tuple(array)


def mergeSort (array) :
    def merge (array, begin, middle, end) :
        i = begin
        j = middle + 1
        while i < middle + 1 :
            if array[begin] > array[middle+1] :
                array[i], array[j+1] = array[middle+1], array[begin]
    def sort (array, begin, end) :
        if begin < end :
            middle = (begin + end) // 2
            sort (array, begin, middle)
            sort (array, middle+1, end)
            merge (array, begin, middle, end)
    
    array = list(array)
    


#def countingSort (array) :
#    array = list(array)
#    temporaryDict = {}
#    for i in range(size) :
#        if array[i] in temporaryDict :
#            temporaryDict[array[i]] += 1
#        else: 
#            temporaryDict[array[i]] = 1
#    print (temporaryDict)
#    # ...


array = createRandomisedArray()
print (array, end = '\n\n')
print (bubbleSort(array), end = '\n\n')
print (insertionSort(array), end = '\n\n')
print (selectionSort(array), end = '\n\n')
countingSort(array)


