#minmax heap module
#logarhytmic insertion
#insert, getmax, getmin functions are WiP
#but the main heap handling functions are finished

def size(k):
    return k[0]

def parent(i):
    return max(i//2, 1)         #necessary so that we can call heapify for i=1

def children_and_grandc(k,i):
    ind = 4*i
    x = 0
    res = []
    while 4*i+x <= size(k)and x < 3:
        res.append(ind+x)
        x += 1
    if 2*i+1 <= size(k):
        res.append(2*i+1)
        res.append(2*i)
    elif 2*i <= size(k): 
        res.append(2*i)
    return res

def heapifymax(k,i):
    index = i
    for x in children_and_grandc(k,i):
        if k[x] > k[index]:
            index = x
    if index >= 4*i:
        k[index], k[i] = k[i], k[index]
        if k[parent(index)] > k[index]:
            k[parent(index)], k[index] = k[index], k[parent(index)]
        heapifymax(k,index)
    elif index >= 2*i:
        k[index], k[i] = k[i], k[index]


def heapifymin(k,i):
    index = i
    for x in children_and_grandc(k,i):
        if k[x] < k[index]:
            index = x
    if index >= 4*i:
        k[index], k[i] = k[i], k[index]
        if k[parent(index)] < k[index]:
            k[parent(index)], k[index] = k[index], k[parent(index)]
        heapifymin(k,index)
    elif index >= 2*i:
        k[index], k[i] = k[i], k[index]


def heapify(k, i):
    lvl = i
    while lvl > 3: lvl //= 4
    if lvl == 1:            #we are in the odd level
        heapifymax(k,i)
    else:
        heapifymin(k,i)     #we are in the even level

def make_heap(k):
    k.append(k[0])
    k[0] = len(k)-1
    for i in range(len(k)//2, 0, -1):
        heapify(k, i)

#test
heap = [i for i in range(12)]
print(heap)
make_heap(heap)
print(heap)
