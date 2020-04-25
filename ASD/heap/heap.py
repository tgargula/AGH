inf = float('inf')

def parent(i): return i // 2
def left(i): return i * 2
def right(i): return i * 2 + 1

def prepare_heap(A): # do iff A[0] != size
    size = len(A)
    A.insert(0, size)

def heapify_max(A, i):
    l = left(i)
    r = right(i)
    if l <= A[0] and A[l] > A[i]: largest = l
    else: largest = i
    if r <= A[0] and A[r] > A[largest]: largest = r
    if largest != i:
        A[largest], A[i] = A[i], A[largest]
        heapify_max(A, largest)

def build_max_heap(A):
    # prepare_heap(A)
    for i in range(A[0] // 2, 0, -1): heapify_max(A, i)

def heap_sort(A):
    build_max_heap(A)
    while A[0] > 0:
        A[1], A[A[0]] = A[A[0]], A[1]
        A[0] -= 1
        heapify_max(A, 1)

def get_max(A):
    return A[1]

def extract_max(A):
    m = A[1]
    A[1] = A[A[0]]
    A[0] -= 1
    heapify_max(A, 1)
    return m

def increase_key(A, i, key):
    A[i] = key
    while i > 1 and A[parent(i)] < A[i]:
        A[i], A[parent(i)] = A[parent(i)], A[i]
        i = parent(i)

def insert_max(A, x):
    A[0] += 1
    if len(A) <= A[0]: A.append(-inf)
    else: A[A[0]] = -inf
    increase_key(A, A[0], x)

def heapify_min(A, i):
    l = left(i)
    r = right(i)
    if l <= A[0] and A[l] < A[i]: smallest = l
    else: smallest = i
    if r <= A[0] and A[r] > A[smallest]: smallest = r
    if smallest != i:
        A[smallest], A[i] = A[i], A[smallest]
        heapify_min(A, smallest)

def build_min_heap(A):
    # prepare_heap(A)
    for i in range(A[0] // 2, 0, -1): heapify_min(A, i)

def heap_sort_min(A):
    build_min_heap(A)
    while A[0] > 0:
        A[1], A[A[0]] = A[A[0]], A[1]
        A[0] -= 1
        heapify_min(A, 1)

def get_min(A):
    return A[1]

def extract_min(A):
    m = A[1]
    A[1] = A[A[0]]
    A[0] -= 1
    heapify_min(A, 1)
    return m

def decrease_key(A, i, key):
    A[i] = key
    while i > 1 and A[parent(i)] > A[i]:
        A[i], A[parent(i)] = A[parent(i)], A[i]
        i = parent(i)

def insert_min(A, key):
    A[0] += 1
    if len(A) <= A[0]: A.append(inf)
    else: A[A[0]] = inf
    decrease_key(A, A[0], x)

# tests
A = [3,2,23,34,3,0,2,34]
prepare_heap(A)
build_max_heap(A)
print(A)
insert_max(A, 36)
print(A)