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

void deleteNode (node *&f, node * prev, node *&t, int &ctr) {
    node * r;
    if(prev == NULL) {
        r = f;
        f = f->next;
        t = f;
    }
    else {
        r = prev->next;
        prev->next = prev->next->next;
    }
    delete r;
    ctr++;
}

int function (node *&f) {
    node * prev = NULL;
    int ctr = 0;
    node * t = f;
    while (t->next != NULL) {
        if (t->v == t->next->v) {
            while (t->next != NULL and t->v == t->next->v) deleteNode(f,prev,t,ctr);
            deleteNode(f,prev,t,ctr);
        }
        else {
            prev = t;
            t = t->next;
        }
    }
    return ctr;
}

void test() {
    node * f = NULL;
    insertFirst(f,7); insertFirst(f,6); insertFirst(f,6); insertFirst(f,3); insertFirst(f,2); insertFirst(f,2); insertFirst(f,1); insertFirst(f,1); insertFirst(f,1);
    output(f); 
    cout << function(f) << " element(s) deleted" << endl;
    output(f);
}

int main() {
    
    test();

    return 0;
}