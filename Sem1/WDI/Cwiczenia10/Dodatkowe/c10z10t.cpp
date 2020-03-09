/*
10. Proszę napisać funkcję, otrzymującą jako parametr wskaźnik na pierwszy
element listy o wartościach typu int, usuwającą wszystkie elementy,
których wartość dzieli bez reszty wartość bezpośrednio następujących
po nich elementów.
*/

#include <iostream>

using namespace std;

struct node {
    int v;
    node * next;
};

void insertFirst (node *&f, int x) {
    node * r = new node;
    r->v = x;
    r->next = f;
    f = r;
}

void output (node * m) {
    while(m != NULL) {
        cout << m->v << " ";
        m = m->next;
    }
    cout << endl;
}

void deleteNode (node *&prev, node *&curr) {
    node * r = curr;

    if (prev == NULL) {
        curr = curr->next;
    }   
    else {
        prev->next = prev->next->next;
        curr = prev->next;
    }
    delete r;
}

void function (node *&f) {
    if (f == NULL) return;
    node * curr = f;
    node * prev = NULL;
    while (curr->next != NULL) {
        if ((curr->next->v) % (curr->v) == 0) deleteNode(prev,curr);
        else {
            prev = curr;
            curr = curr->next;
        }
    }
}

void test() {
    node *f = NULL;
    insertFirst(f,80);
    insertFirst(f,75);
    insertFirst(f,25);
    insertFirst(f,23);
    insertFirst(f,20);
    insertFirst(f,10);
    insertFirst(f,5);
    insertFirst(f,4);

    output(f);

    function(f);

    output(f);
}

int main() {
    
    test();

    return 0;
}