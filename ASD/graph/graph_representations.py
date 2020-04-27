class List:
    def __init__(self):              # O(1)
        self.first = None
        self.second = None
        self.next = None
    
    def add(self, first, second):    # O(1)
        new = List()
        new.first = first
        new.second = second
        new.next = self.next
        self.next = new
    
    def exist(self, first, second):  # O(E)
        while self.next != None:
            self = self.next
            if self.first == first and self.second == second: return True
        return False
    
    def edges_from_node(self, node):  # O(E) – thus it is better to do it while overviewing
        edges = []
        curr = self
        while curr.next != None:
            curr = curr.next
            if curr.first == node: edges.append(curr.second)
        return edges

class AdjacencyMatrix:
    def __init__(self, V):  # O(V^2)
        self.matrix = [[0 for _ in range(V)] for _ in range(V)] 
        self.V = V
    
    def add(self, first, second):    # O(1)
        self.matrix[first][second] = 1
    
    def exist(self, first, second):  # O(1)
        return self.matrix[first][second] == 1
    
    def edges_from_node(self, node): # O(V) – thus it is better to do it while overviewing
        edges = []
        for i in range(self.V):
            if self.matrix[node][i] == 1: edges.append(i)
        return edges

class AdjacencyList:
    def __init__(self, V):  # O(V)
        self.graph = [[] for _ in range(V)]
    
    def add(self, first, second):    # O(1)
        self.graph[first].append(second) # assuming that append has got O(1)
    
    def exist(self, first, second):  # O(V)
        return second in self.graph[first]
    
    def edges_from_node(self, node): # O(1); overview – O(deg(node))
        return self.graph[node]


# tests

A = List()
A.add(1,2)
A.add(1,3)
A.add(5,4)
A.add(4,5)
A.add(5,3)
print(A.exist(1,3))
print(A.exist(1,4))
print(A.edges_from_node(1))


A = AdjacencyMatrix(6)
A.add(1,2)
A.add(1,3)
A.add(5,4)
A.add(4,5)
A.add(5,3)
print(A.exist(1,3))
print(A.exist(1,4))
print(A.edges_from_node(1))

A = AdjacencyList(6)
A.add(1,2)
A.add(1,3)
A.add(5,4)
A.add(4,5)
A.add(5,3)
print(A.exist(1,3))
print(A.exist(1,4))
print(A.edges_from_node(1))