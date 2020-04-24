class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

# all data structures have got a sentinel node

def empty(node):
    return node.next == None

# queue

def enqueue(node, val):
    while node.next != None: node = node.next
    node.next = Node(val)

def dequeue(node): 
    val = node.next.val
    node.next = node.next.next
    return val

# stack

def push(node, val):
    new = Node(val)
    new.next = node.next
    node.next = new

def pop(node):
    val = node.next.val
    node.next = node.next.next
    return val

# deque

def append(node, val):
    while node.next != None: node = node.next
    node.next = Node(val)

def appendleft(node, val):
    new = Node(val)
    new.next = node.next
    node.next = new

def popright(node):
    val = node.next.val
    node.next = node.next.next
    return val

def popleft(node):
    while node.next != None: node = node.next
    val = node.next.val
    node.next = None
    return val

# double_linked_list

class DoubleNode:
    def __init__(self, val):
        self.prev = self
        self.val = val
        self.next = self
    
# deque

def d_empty(node):
    return node.next == node and node.prev == node

def d_append(node, val):
    new = DoubleNode(val)
    new.prev = node.prev
    new.next = node
    node.prev.next = new
    node.prev = new

def d_appendleft(node, val):
    new = DoubleNode(val)
    new.prev = node
    new.next = node.next
    node.next.prev = new
    node.next = new

def d_pop(node):
    val = node.prev.val
    node.prev.prev.next = node
    node.prev = node.prev.prev
    return val

def d_popleft(node):
    val = node.next.val
    node.next.next.prev = node
    node.next = node.next.next
    return val

node = DoubleNode(None)
d_append(node, 5)
d_append(node, 10)
d_appendleft(node, 15)
d_append(node, 20)
for _ in range(4): print(d_popleft(node))
