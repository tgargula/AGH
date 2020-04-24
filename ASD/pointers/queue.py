# Queue implementation
#
# Basic queue implementation using C++-like pointers

class Queue:
    def __init__(self):
        self.value = None
        self.next = None

    def print_queue(self):
        if not self.empty():
            while self.next != None:
                print (self.next.value, end=" ")
                self = self.next
        print()
    
    def empty(self):
        return self.next == None
    
    def enqueue(self, value):
        while self.next != None: self = self.next
        self.next = Queue()
        self.next.value = value
    
    def dequeue(self):
        if not self.empty():
            first = self.next.value
            self.next = self.next.next
        return first
            
# test
A = Queue()
for i in range(1,10): A.enqueue((4 * i) % 7)
A.print_queue()
print(A.dequeue())
A.print_queue()