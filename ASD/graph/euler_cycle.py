class Node:
    def __init__(self, value):
        self.value = value

class AdjacencyList:
    def __init__(self, V):  # O(V)
        self.graph = [[] for _ in range(V)]
    
    def add(self, v, u):    # O(1)
        self.graph[v.value].append(u)
        self.graph[u.value].append(v)
    
    def remove(self, v, u): # O(n)
        self.graph[v.value].remove(u)
        self.graph[u.value].remove(v)

    def neighbors(self, node): # O(1)
        return self.graph[node.value]

def euler_cycle(G, V):
    C = [0]
    for u in V: DFS(G, C, u)
    return C

def DFS(G, C, u):
    for v in G.neighbors(u):
        G.remove(u, v)
        DFS(G, C, v)
        C.append(u.value)

n = 5
V = [Node(i) for i in range(n)]
G = AdjacencyList(n)
G.add(V[1], V[2])
G.add(V[2], V[0])
G.add(V[0], V[1])
G.add(V[1], V[4])
G.add(V[4], V[3])
G.add(V[3], V[1])
print(euler_cycle(G, V))