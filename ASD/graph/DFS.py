class Node:
    def __init__(self, value):
        self.value = value
        self.parent = None
        self.t1 = None
        self.t2 = None
        self.color = "white"

class AdjacencyList:
    def __init__(self, V):  # O(V)
        self.graph = [[] for _ in range(V)]
    
    def add(self, v, u):    # O(1)
        self.graph[v.value].append(u)
    
    def neighbors(self, node): # O(1)
        return self.graph[node.value]

def DFS(G, V):
    time = 0
    for u in V:
        if u.color == "white":
            time = DFSvisit(G, u, time)
        
def DFSvisit(G, u, time):
    time += 1
    u.t1 = time
    u.color = "grey"
    for v in G.neighbors(u):
        if v.color == "white":
            v.parent = u
            time = DFSvisit(G, v, time)
    u.color = "black"
    time += 1
    u.t2 = time
    return time

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
DFS(G, V)
for v in V:
    print("Value:", v.value)
    if v.parent == None: print("Parent:", None)
    else: print("Parent:", v.parent.value)
    print("t1:", v.t1)
    print("t2:", v.t2)
    print("color:", v.color)