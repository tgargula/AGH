import sys

def parent(i): return i//2
def left(i): return i*2
def right(i): return i*2+1
def sons_and_grandsons(i):
    result = [
                left(i), right(i),
                left(left(i)), left(right(i)), right(left(i)), right(right(i))
             ]
    return result

class MinMaxHeap:
    def __init__(self, A):
        self.heap = [len(A)]
        self.heap.extend(A)
        self.build_heap()
    
    def print(self):
        print ("[",end="")
        for i in range(1, self.size()-1): print(self.heap[i],end=", ")
        print (self.heap[self.size()],"]", sep="")
    
    def size(self): return self.heap[0]
    def sizePlusOne(self): self.heap[0]+=1
    def sizeMinusOne(self): self.heap[0]-=1

    def build_heap(self):
        for i in range(self.size()//2, 0, -1):
            self.heapify(i)
    
    def heapify(self, i):
        level = i
        while level >= 4: level //= 4
        if level == 1:  # odd level
            self.heapify_min(i)
        else:
            self.heapify_max(i)
    
    def heapify_max(self, i):
        def index_max(i):
            M = i
            for j in sons_and_grandsons(i):
                if j > self.size(): break
                if self.heap[M] < self.heap[j]: M = j
            return M
            
        if left(i) <= self.size():  # has got children
            M = index_max(i)
            if M >= 4*i:    # is a grandchild of i
                if self.heap[M] > self.heap[i]:
                    self.heap[M], self.heap[i] = self.heap[i], self.heap[M]
                    if self.heap[M] < self.heap[parent(M)]:
                        self.heap[M], self.heap[parent(M)] = self.heap[parent(M)], self.heap[M]
                    self.heapify_max(M)
            elif self.heap[M] > self.heap[i]:
                self.heap[M], self.heap[i] = self.heap[i], self.heap[M]
    
    def heapify_min(self, i):
        def index_min(i):
            m = i
            for j in sons_and_grandsons(i):
                if j > self.size(): break
                if self.heap[m] > self.heap[j]: m = j
            return m
        
        if left(i) <= self.size():  # has got children
            m = index_min(i)
            if m >= 4*i:    # is a grandchild of i
                if self.heap[m] < self.heap[i]:
                    self.heap[m], self.heap[i] = self.heap[i], self.heap[m]
                    if self.heap[m] > self.heap[parent(m)]:
                        self.heap[m], self.heap[parent(m)] = self.heap[parent(m)], self.heap[m]
                    self.heapify_min(m)
            elif self.heap[m] < self.heap[i]:
                self.heap[m], self.heap[i] = self.heap[i], self.heap[m]

    def insert(self, value):
        if self.size() == len(self.heap)-1:
            self.heap.append(value)
        
        self.sizePlusOne()
        self.heap[self.size()] = value
        
        i = self.size()
        while i > 1:
            self.heapify(parent(i))
            i = parent(i)

    
    def extract_min(self):
        self.heap[1], self.heap[self.size()] = self.heap[self.size()], self.heap[1]
        self.sizeMinusOne()
        self.heapify(1)
        return self.heap[self.size()+1]
    
    def extract_max(self):
        if self.heap[2] >= self.heap[3]: i = 2
        else: i = 3
        self.heap[i], self.heap[self.size()] = self.heap[self.size()], self.heap[i]
        self.sizeMinusOne()
        self.heapify(i)
        return self.heap[self.size()+1]


#test
A = [2,3,4,1,234,32,3,532,543,3,24,1]
heap = MinMaxHeap(A)
print(heap.heap)
heap.insert(0)
heap.print()
m = heap.extract_min()
M = heap.extract_max()
print("Max: ", M)
print("Min: ", m)
heap.print()