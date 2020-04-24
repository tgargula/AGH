class Node:
    def __init__(self):
        self.next = None
        self.value = None


def printNode (L):
    while L.next != None:
        print (L.next.value, end=" ")
        L = L.next
    print()


def insert (L, value):
    temp = Node()
    temp.value = value
    while L.next != None and L.next.value < value:
        L = L.next

    temp.next = L.next
    L.next = temp


L = Node()

for i in range(10):
    insert(L,i%3)

printNode(L)