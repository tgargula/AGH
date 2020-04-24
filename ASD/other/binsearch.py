def binsearch(A, x):
    left = 0
    right = len(A) - 1
    while left <= right:
        i = (left + right) // 2
        if x < A[i]: right = i - 1
        elif x > A[i]: left = i + 1
        else: return i
    return None

def trinary_search(A, x):
    left = 0
    right = len(A) - 1
    while left < right:
        i = (left + right) // 3
        j = 2 * i
        if x < A[i]: right = i - 1
        elif x == A[i]: return i
        elif x > A[j]: left = j + 1
        elif x == A[j]: return j
        else:
            left = i + 1
            right = j - 1
    return None

print(binsearch([1,2,3,5,6,7,9], 3))
print(binsearch([1,2,3,5,6,7,9], 4))
print(binsearch([1,2,3,5,6,7,9], 1))
print(binsearch([1,2,3,5,6,7,9], 9))

print(trinary_search([1,2,3,5,6,7,9], 3))
print(trinary_search([1,2,3,5,6,7,9], 4))
print(trinary_search([1,2,3,5,6,7,9], 1))
print(trinary_search([1,2,3,5,6,7,9], 9))