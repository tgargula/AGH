# Find the smallest and the largest number in array in computational complexity O(3/2n)
# Solution:
# compare 0. vs 1., 2. vs 3., ... and compare smaller with min and larger with max

def findMaxAndMin(array, mini = 64752576246245327885765542574326989857252375327635762825, maxi = -7326586752136524132872568152179856128176512492757423):
    if(len(array) % 2 == 0):
        for i in range(0, len(array), 2):
            if(array[i] > array[i+1]):
                if(maxi < array[i]): maxi = array[i]
                if(mini > array[i+1]): mini = array[i+1]
            else:
                if(maxi < array[i+1]): maxi = array[i+1]
                if(mini > array[i]): mini = array[i]
    else:
        for i in range(0, len(array) - 1, 2):
            if(array[i] > array[i+1]):
                if(maxi < array[i]): maxi = array[i]
                if(mini > array[i+1]): mini = array[i+1]
            else:
                if(maxi < array[i+1]): maxi = array[i+1]
                if(mini > array[i]): mini = array[i]
        if(maxi < array[len(array)-1]): maxi = array[len(array)-1]
        if(mini > array[len(array)-1]): mini = array[len(array)-1]
    
    return mini, maxi

################

array = [1,2,4,776,356,2543,7694635676,5324,5345,5347,897,24,-11635465431]
print(findMaxAndMin(array))