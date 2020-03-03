import sys

def parent(i): return i//2
def left(i): return i*2
def right(i): return i*2+1
def sonsAndGrandsons(i):
    result = [
                left(i), right(i),
                left(left(i)), left(right(i)), right(left(i)), right(right(i))
             ]
    return result

class minmaxHeap:
    def __init__(self, table):
        self.heap = [len(table)]
        self.heap.extend(table)
        self.buildHeap()
    
    def print(self):
        print ("[",end="")
        for i in range(1, self.size()-1): print(self.heap[i],end=", ")
        print (self.heap[self.size()],"]", sep="")
    
    def size(self): return self.heap[0]
    def sizePlusOne(self): self.heap[0]+=1
    def sizeMinusOne(self): self.heap[0]-=1

    def buildHeap(self):
        for i in range(self.size()//2, 0, -1):
            self.heapify(i)
    
    def heapify(self, i):
        level = i
        while level >= 4: level //= 4
        if level == 1:  # odd level
            self.heapifyMin(i)
        else:
            self.heapifyMax(i)
    
    def heapifyMax(self, i):
        def indexOfTheBiggestChildOrGrandchild(i):
            M = i
            for j in sonsAndGrandsons(i):
                if j > self.size(): break
                if self.heap[M] < self.heap[j]: M = j
            return M
            
        if left(i) <= self.size():  # has got children
            M = indexOfTheBiggestChildOrGrandchild(i)
            if M >= 4*i:    # is a grandchild of i
                if self.heap[M] > self.heap[i]:
                    self.heap[M], self.heap[i] = self.heap[i], self.heap[M]
                    if self.heap[M] < self.heap[parent(M)]:
                        self.heap[M], self.heap[parent(M)] = self.heap[parent(M)], self.heap[M]
                    self.heapifyMax(M)
            elif self.heap[M] > self.heap[i]:
                self.heap[M], self.heap[i] = self.heap[i], self.heap[M]
    

    def heapifyMin(self, i):
        def indexOfTheSmallestChildOrGrandchild(i):
            m = i
            for j in sonsAndGrandsons(i):
                if j > self.size(): break
                if self.heap[m] > self.heap[j]: m = j
            return m
        
        if left(i) <= self.size():  # has got children
            m = indexOfTheSmallestChildOrGrandchild(i)
            if m >= 4*i:    # is a grandchild of i
                if self.heap[m] < self.heap[i]:
                    self.heap[m], self.heap[i] = self.heap[i], self.heap[m]
                    if self.heap[m] > self.heap[parent(m)]:
                        self.heap[m], self.heap[parent(m)] = self.heap[parent(m)], self.heap[m]
                    self.heapifyMin(m)
            elif self.heap[m] < self.heap[i]:
                self.heap[m], self.heap[i] = self.heap[i], self.heap[m]

    def insert(self, value):
        if self.size() == len(self.heap)-1:
            self.heap.append(value)
        
        self.sizePlusOne()
        self.heap[self.size()] = value
        #self.heapify(self.size())
        self.buildHeap()    # It could be done easier 
        # level = self.size()
        # while level >= 4: level //= 4
        # if level == 1:  # odd level
        #     j = self.size()
        #     while j > 3 and self.heap[j] < self.heap[parent(parent(j))]:
        #         self.heap[i], self.heap[parent(parent(i))] = self.heap[parent(parent(i))], self.heap[i]
        #         i = parent(parent(i))
    
    def extractMin(self):
        self.heap[1], self.heap[self.size()] = self.heap[self.size()], self.heap[1]
        self.sizeMinusOne()
        self.heapify(1)
        return self.heap[self.size()+1]
    
    def extractMax(self):
        if self.heap[2] >= self.heap[3]: i = 2
        else: i = 3
        self.heap[i], self.heap[self.size()] = self.heap[self.size()], self.heap[i]
        self.sizeMinusOne()
        self.heapify(i)
        return self.heap[self.size()+1]


#test
table = [2,3,4,1,234,32,3,532,543,3,24,1]
heap = minmaxHeap(table)
print(heap.heap)
heap.insert(0)
heap.print()
m = heap.extractMin()
M = heap.extractMax()
print("Max: ", M)
print("Min: ", m)
heap.print()