/*
3. Proszę napisać funkcję scalającą dwie posortowane listy w jedną posortowaną
listę. Do funkcji należy przekazać wskazania na pierwsze elementy obu list,
funkcja powinna zwrócić wskazanie do scalonej listy.
- funkcja iteracyjna (merge1);
- funkcja rekurencyjna (merge2)
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

void output(node *m) {
    while(m != NULL) {
        cout << m->v << " ";
        m = m->next;
    }
    cout << endl;
}

node * merge1 (node * f, node * s) {
    if (f == NULL) return s;
    if (s == NULL) return f;

    node * n;
    
    if (f->v >= s->v) {
        if (s->v == f->v) f = f->next; 
        n = s;
        s = s->next;
    }
    else {
        n = f;
        f = f->next;
    }

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

// Kod przepisany z zajęć, ale nie działa
node * merge2 (node * f, node * s) {
    if (f == NULL) return s;
    if (s == NULL) return f;
    if (f->v >= s->v) {
        s->next = merge2(f,s->next);
        return s;
    }
    else {
        f->next = merge2(f->next,s);
        return f;
    }
}

void test() {
    node * f = NULL;
    node * s = NULL;

    for(int i = 10; i > 0; i--) {
        insertFirst(f,2*i);
        insertFirst(s,3*i);
    }
    
    output(f);
    output(s);
    
    output(merge1(f,s));
    output(merge1(s,f));

    output(merge2(f,s));
}

int main() {
    
    test();

    return 0;
}