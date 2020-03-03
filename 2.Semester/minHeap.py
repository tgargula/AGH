import sys

def parent(i): return i//2
def left(i): return i*2
def right(i): return i*2+1

class minHeap:    
    def __init__(self, table):
        self.heap = [len(table)]
        self.heap.extend(table)
        self.buildHeap()

    def heapify(self, i):
        l = left(i)
        r = right(i)
        M = i
        if l <= self.heap[0] and self.heap[l] < self.heap[M]: M = l
        if r <= self.heap[0] and self.heap[r] < self.heap[M]: M = r
        if M != i:
            self.heap[i], self.heap[M] = self.heap[M], self.heap[i]
            self.heapify(M)

    def buildHeap(self):
        for i in range(self.heap[0]//2, 0, -1):
            self.heapify(i)

    def heapSort(self):
        buildHeap(self)
        for i in range(self.heap[0],1,-1):
            self.heap[i], self.heap[1] = self.heap[1], self.heap[i]
            self.heap[0] -= 1
            self.heapify(1)

    def getMin(self):
        if self.heap[0] == 0: sys.exit()
        result = self.heap[1]
        self.heap[1] = self.heap[self.heap[0]]
        self.heap[0] -= 1
        self.heapify(1)
        return result

    def insert(self,value):
        if self.heap[0] == len(self)-1: self.append(value)
        else:
            self.heap[0] += 1
            self.heap[self.heap[0]] = value
            i = self.heap[0]
            while i > 1 and self.heap[i] < self.heap[parent(i)]:
                self.heap[i], self.heap[parent(i)] = self.heap[parent(i)], self.heap[i]
                i = parent(i)

table = [2,3,4,234,32,3,543,532,3,24]
heap = minHeap(table)

print(heap.heap)