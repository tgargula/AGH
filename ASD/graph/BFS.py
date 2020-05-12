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
E = [ (0, 1), (1, 2), (0, 2), (4, 1), (3, 4), (0, 3), (2, 3) ]
for e in E:
    G.add(V[e[0]], V[e[1]])
BFS(G, V[0])
for v in V:
    print("Value:", v.value)
    if v.parent == None: print("Parent:", None)
    else: print("Parent:", v.parent.value)
    print("d:", v.d)
    print("color:", v.color)