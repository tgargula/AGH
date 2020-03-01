# It has to be continued


class Node:
    def __init__(self):
        self.next = None
        self.value = None


    def printNode (L):
        while L.next != None:
            print (L.next.value, end=" ")
            L.next = L.next.next
        print()


    def insert (L, value):
        temp = Node()
        temp.value = value
        while L.next != None : #and L.next.value < value:
            L.next = L.next.next

        temp.next = L.next
        L.next = temp


    def reverse (L):
        if L.next == None: return L
        T = L.next
        H = reverse(T)
        T.next = L
        H.next = None
        return H



L = Node()

for i in range(10):
    Node.insert(L,i)

Node.printNode(L)
