/*
3. Dana jest niepusta lista, proszę napisać funkcję usuwającą co drugi
element listy. Do funkcji należy przekazać wskazanie na pierwszy element listy.
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

void deleteEverySecond (node * f) {
    node * r = f;
    while (r != NULL and r->next != NULL) {
        node * h = r->next;
        r->next = h->next;
        delete h;
        r = r->next;
    }
}

void test () {
    node * f = NULL;

    for (int i = 1; i <= 15; i++) insertFirst(f,i);

    output(f);
    deleteEverySecond(f);
    output(f);
    deleteEverySecond(f);
    output(f);
}

int main() {

    test();
    
    return 0;
}