import random

class Node:
    def __init__ (self, val):
        self.val = val
        self.next = None

    def add_number (self, val): # test function
        temp = self.next
        self.next = Node(val)
        self.next.next = temp

class TwoLists:
    def __init__ (self, even, odd):
        self.even = even
        self.odd = odd

def split (linked_list):
    even_head = Node(-1); odd_head = Node(-1) # create sentinel nodes
    even = even_head; odd = odd_head
    while linked_list != None:
        if linked_list.val %2 == 0:
            even.next = linked_list
            even = even.next
        else:
            odd.next = linked_list
            odd = odd.next
        linked_list = linked_list.next
    odd.next = even.next = None
    return TwoLists(even_head.next, odd_head.next) # remove sentinel nodes by returning next nodes

def output (two_lists): # test function
    print("Odd:", end=" ")
    while two_lists.odd != None: 
        print(two_lists.odd.val, end=" ")
        two_lists.odd = two_lists.odd.next
    print("\nEven:", end=" ")
    while two_lists.even != None:
        print(two_lists.even.val, end=" ")
        two_lists.even = two_lists.even.next
    print()


linked_list = Node(3)
for _ in range(100): linked_list.add_number(random.randint(1,1000))

output(split(linked_list))