def insertion_sort(A):
    for i in range(len(A)):
        key = A[i]
        k = i-1
        while k >= 0 and A[k] > key:
            A[k+1] = A[k]
            k -= 1
        A[k+1] = key

def bucket_sort(A):
    n = len(A)
    m = len(A) // 2 # should be propotional to len(A)
    max_value = max(A)
    buckets = [[] for _ in range(m+1)] # subset of [0, max_value]
    for num in A: buckets[int(num / max_value * m)].append(num)
    for bucket in buckets: insertion_sort(bucket)
    i = 0
    B = []
    for bucket in buckets:
        B[i:] = bucket
        i += len(bucket)
    A[:] = B

A = [5,3,2.7,10.2, 0, 21.37, 5.3, 15.6, 21.36, 2.1]
bucket_sort(A)
print(A)