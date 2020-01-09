/*
3. Proszę napisać funkcję scalającą dwie posortowane listy w jedną posortowaną
listę. Do funkcji należy przekazać wskazania na pierwsze elementy obu list,
funkcja powinna zwrócić wskazanie do scalonej listy.
- funkcja iteracyjna (merge1);

Wersja z wartownikiem na początku
*/

#include <iostream>

using namespace std;

struct node {
    int v;
    node * next;
};

void insertFirst (node * f, int x) {
    node * r = new node;
    r->v = x;
    r->next = f->next;
    f->next = r;
}

void output (node * f) {
    while (f->next != NULL) {
        f = f->next;
        cout << f->v << " ";
    }
    cout << endl;
}

node * merge1 (node * f, node * s) {
    f = f->next;
    s = s->next;
    
    if (f == NULL) return s;
    if (s == NULL) return f;

    node * n = new node;
    node * N = n;
    while (f != NULL and s != NULL) {
        if (f->v >= s->v) {
            if (f->v == s->v) f = f->next;
            n->next = s;
            s = s->next;
        }
        else {
            n->next = f;
            f = f->next;
        }
        n = n->next;
    }

    if (f != NULL) n->next = f;
    else n->next = s;

    return N;
}

void test() {
    node * f = new node;
    node * s = new node;

    for(int i = 10; i > 0; i--) {
        insertFirst(f,2*i);
        insertFirst(s,3*i);
    }
    
    output(f);
    output(s);
    
    output(merge1(f,s));
    output(merge1(s,f)); 
}

int main() {
    
    test();

    return 0;
}