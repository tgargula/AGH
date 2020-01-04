/*
16. Elementy w liście są uporządkowane według wartości klucza.
Proszę napisać funkcję usuwającą z listy elementy o nieunikalnym kluczu.
Do funkcji przekazujemy wskazanie na pierwszy element listy,
funkcja powinna zwrócić liczbę usuniętych elementów.
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

void output (node * f) {
    while (f != NULL) {
        cout << f->v << " ";
        f = f->next;
    }
    cout << endl;
}

void deleteFirst(node *&f) {
    node * r = f;
    f = f->next;
    delete r;
}

void deleteNode(node * prev) {
    node * r = prev->next;
    prev->next = prev->next->next;
    delete r;
}

int function (node *&t) {
    node * prev = NULL;
    int ctr = 0;
    node * f = t;
    while (t->next != NULL) {
        if (t->v == t->next->v) {
            while (t->next != NULL and t->v == t->next->v) {
                if(prev == NULL) { deleteFirst(t); f = t; }
                else deleteNode(prev);
                ctr++;
            }
            if(prev == NULL) { deleteFirst(t); f = t; }
            else deleteNode(prev);
            ctr++;
        }
        else {
            prev = t;
            t = t->next;
        }
    }
    t = f;
    return ctr;
}

int main() {
    node * f = NULL;
    insertFirst(f,7); insertFirst(f,6); insertFirst(f,6); insertFirst(f,3); insertFirst(f,2); insertFirst(f,2); insertFirst(f,1); insertFirst(f,1); insertFirst(f,1);
    output(f); 
    cout << function(f) << endl;
    output(f);

    return 0;
}