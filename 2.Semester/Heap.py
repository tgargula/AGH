import sys

def parent(i): return i//2
def left(i): return i*2
def right(i): return i*2+1

def heapify(H, i):
    l = left(i)
    r = right(i)
    M = i
    if l <= H[0] and H[l] > H[M]: M = l
    if r <= H[0] and H[r] > H[M]: M = r
    if M != i:
        H[i], H[M] = H[M], H[i]
        heapify(H,M)

def buildHeap(H):
    for i in range(H[0]//2, 0, -1):
        heapify(H,i)

def heapSort(H):
    buildHeap(H)
    for i in range(H[0],1,-1):
        H[i], H[1] = H[1], H[i]
        H[0] -= 1
        heapify(H,1)

def getMax(H):
    if H[0] == 0: sys.exit()
    result = H[1]
    H[1] = H[H[0]]
    H[0] -= 1
    heapify(H,1)
    return result

def insert(H,value):
    if H[0] == len(H)-1: H.append(value)
    else:
        H[0] += 1
        H[H[0]] = value
        i = H[0]
        while i > 1 and H[i] > H[parent(i)]:
            H[i], H[parent(i)] = H[parent(i)], H[i]
            i = parent(i)

