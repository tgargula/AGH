class Node:
    def __init__(self, value):
        self.value = value
        self.color = "white"

class AdjacencyList:
    def __init__(self, V):  # O(V)
        self.graph = [[] for _ in range(V)]
    
    def add(self, v, u):    # O(1)
        self.graph[v.value].append(u)
    
    def neighbors(self, node): # O(1)
        return self.graph[node.value]
    
def topological_sorting(G, V):
    L = []
    for u in V:
        if u.color == "white":
            DFS(G, L, u)
    L.reverse()
    return L

def DFS(G, L, u):
    u.color = "grey"
    for v in G.neighbors(u):
        if v.color == "grey":
            raise Exception("Graph is not a DAG")
        if v.color == "white":
            DFS(G, L, v)
    L.append(u.value)
    u.color = "black"

# test
n = 5
V = [Node(i) for i in range(n)]
G = AdjacencyList(n)
G.add(V[0], V[1])
G.add(V[1], V[3])
G.add(V[0], V[3])
G.add(V[0], V[4])
G.add(V[2], V[4])
G.add(V[0], V[2])
G.add(V[3], V[2])
print(topological_sorting(G, V))