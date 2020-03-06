# Comb sort algorithm
#
# DESCRIPTION
# Works similar to bubble sort, but the gap is bigger
# ...
#
# Time complexity:  O(n log n) – best case
# Time complexity:  O(n^2) – worst case
# Space complexity: O(1) 

divisor = 1.3

def combSort(table):
    end = length = len(table)
    while True:
        end = int(end/divisor)
        i, j = 0, end
        while j < length:
            if table[i] < table[j]:
                table[i], table[j] = table[j], table[i]
            i += 1; j += 1
        if end == 1: break
    
    isSorted = False
    while not isSorted:
        isSorted = True
        for k in range(1, length):
            if table[k-1] > table[k]:
                table[k-1], table[k] = table[k], table[k-1]
                isSorted = False

tab = [1,2,3,2,2,3,21,34,54,3,343,221,23,2]

combSort(tab)

print(tab)