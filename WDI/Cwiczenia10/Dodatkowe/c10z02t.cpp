/*
2. Proszę napisać funkcję usuwającą ostatni element listy.
Do funkcji należy przekazać wskazanie na pierwszy element listy.
*/

#include <iostream>

using namespace std;

struct node {
    int v;
    node * next;
};

void output (node * f) {
    while (f != NULL) {
        cout << f->v << " ";
        f = f->next;
    }
    cout << endl;
}

void insertLast (node *&f, int x) {
    node * r = new node;
    r->v = x;
    r->next = NULL;

    if (f == NULL) { f = r; return; }

    node * prev = f;
    node * curr = f;
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
    }
    
    prev->next = r;
}

void deleteLast (node *&f) {
    if (f == NULL) return;
    
    node * curr = f;
    node * prev = NULL;

    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL) { delete f; return; }

    prev->next = NULL;
    delete curr;
}

void test (node * f) {
    for (int i = 1; i <= 10; i++) insertLast(f,i);
    output(f);
    deleteLast(f);
    output(f);
}

int main() {
    node *f = NULL;

    test(f);

    return 0;
}