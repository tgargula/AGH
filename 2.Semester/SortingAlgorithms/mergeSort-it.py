# Merge sort algorithm
#
# This merge sort uses naturally sorted fragments and merges each of two following fragments
# It is done iteratively

def mergeSort (table):
    def merge(tab1, tab2):
        i = j = 0
        res = []
        while i < len(tab1) and j < len(tab2):
            if tab1[i] < tab2[j]:
                res.append(tab1[i])
                i += 1
            else:
                res.append(tab2[j])
                j += 1
        
        if i == len(tab1): res.extend(tab2[j:])
        else: res.extend(tab1[i:])
        
        return res
    
    def sortedFragment(i):
        j = i+1
        while j < len(table) and table[j-1] <= table[j]: j += 1
        return table[i:j]
    
    def update(A, start, end):
        for i in range (end-start):
            table[i+start] = A[i]

    while True:
        i = 0
        while i < len(table):
            start = i
            tab1 = sortedFragment(i)
            i += len(tab1)
            tab2 = sortedFragment(i)
            i += len(tab2)
            M = merge(tab1, tab2)
            update(M, start, i)
        if tab2 == []: break


table = [1,2,31,4,6,321,2,3,43,2,2,3]
mergeSort(table)
print(table)