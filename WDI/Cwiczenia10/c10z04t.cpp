/*
4. Proszę napisać funkcję, która dla podanej listy odwraca kolejność jej elementów.
*/

#include <iostream>

using namespace std;

struct node {
    int v;
    node * next;
};

void insertFirst (node *&f, int x) {
    node *r = new node;
    r->v = x;
    r->next = f;
    f = r;
}

void output(node * m) {
    while(m != NULL) {
        cout << m->v << " ";
        m = m->next;
    }
    cout << endl;
}

node * reverseList (node * head) {
    if (head == NULL or head->next == NULL) return head;
    
    node * prev = head;
    node * curr = head->next;
    node * foll = head->next;

    prev->next = NULL;

    while (curr != NULL) {
        foll = foll->next;
        curr->next = prev;
        prev = curr;
        curr = foll;
    }

    return prev;
}

void test() {
    node * head = new node;

    for (int i = 1; i <= 10; i++) insertFirst(head,i);

    output(head);
    output(reverseList(head));
}

int main() {
    
    test();

    return 0;
}