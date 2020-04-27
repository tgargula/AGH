import queue

inf = float('Inf')

class Node:
    def __init__(self, value):
        self.value = value
        self.parent = None
        self.d = inf
        self.color = "white"

class AdjacencyList:
    def __init__(self, V):  # O(V)
        self.graph = [[] for _ in range(V)]
    
    def add(self, v, u):    # O(1)
        self.graph[v.value].append(u)
    
    def neighbors(self, node): # O(1)
        return self.graph[node.value]

def BFS(G, s):
    s.color = "grey"
    s.d = 0
    Q = queue.Queue()
    Q.put(s)
    while not Q.empty():
        u = Q.get()
        for v in G.neighbors(u):
            if v.color == "white":
                v.color = "grey"
                v.d = u.d + 1
                v.parent = u
                Q.put(v)
        u.color = "black"

# test
n = 5
V = [Node(i) for i in range(n)]
G = AdjacencyList(n)
G.add(V[0], V[1])
G.add(V[1], V[2])
G.add(V[0], V[2])
G.add(V[4], V[1])
G.add(V[3], V[4])
G.add(V[0], V[3])
G.add(V[2], V[3])
BFS(G, V[0])
for v in V:
    print("Value:", v.value)
    if v.parent == None: print("Parent:", None)
    else: print("Parent:", v.parent.value)
    print("d:", v.d)
    print("color:", v.color)