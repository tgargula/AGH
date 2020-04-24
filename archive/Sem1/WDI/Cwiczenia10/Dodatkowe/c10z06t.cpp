/*
6. Lista zawiera niepowtarzające się elementy. Proszę napisać funkcję,
do której przekazujemy wskaźnik na początek oraz wartość klucza.
Jeżeli element o takim kluczu występuje w liście należy go usunąć z listy.
Jeżeli elementu o zadanym kluczu brak w liście należy element o takim kluczu
wstawić do listy.
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
    while (m != NULL) {
        cout << m->v << " ";
        m = m->next;
    }
    cout << endl;
}

void deleteFirst (node *&f) {
    node * r = f;
    f = f->next;
    delete r;
}

void deleteKey (node *&f) {
    node * r = f->next;
    f->next = f->next->next;
    delete r;
}

void insertKey (node *&f, int key) {
    node * n = new node;
    n->v = key;
    n->next = f->next;
    f->next = n;
}

void Function (node *&f, int key) {
    if (f == NULL) { insertFirst(f,key); return; }
    if (f->v == key) { deleteFirst(f); return; }
    
    // Assuming that f is a sorted list
    node * prev;
    node * curr = f;
    do {
        prev = curr;
        curr = curr->next;
    }   while (curr != NULL and curr->v < key);

    if (curr->v == key) { deleteKey(prev); return; }
    
    insertKey(prev, key);
}

void test() {
    node * f = NULL;

    for (int i = 20; i > 0; i-=2) insertFirst(f,i);

    output(f);

    Function(f,6);

    output(f);

    Function(f,5);
    
    output(f);
}

int main() {
    
    test();

    return 0;
}