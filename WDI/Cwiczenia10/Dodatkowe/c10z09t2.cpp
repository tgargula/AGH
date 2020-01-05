/*
9. Proszę napisać funkcję, otrzymującą jako parametr wskaźnik na pierwszy
element listy o wartościach typu int, usuwającą wszystkie elementy,
których wartość jest mniejsza od wartości bezpośrednio poprzedzających
je elementów.
v2 -- usuwa tylko i wyłącznie poprzedzające elementy, które spełniają warunek
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

void deleteNextNode(node * f) {
    node * r = f->next;
    f->next = f->next->next;
    delete r;
}

void function (node * f) {
    bool tab[100] = {false};
    int ctr = 0;
    node * F = f;
    while (f->next != NULL) {
        if(f->next->v < f->v) tab[ctr] = true;
        f = f->next;
        ctr++;
    }

    int i = 0;
    while (F != NULL and F->next != NULL) {
        if(tab[i]) deleteNextNode(F);
        else F = F->next;
        i++;
    }
}

void test() {
    node * f = NULL;
    insertFirst(f,5); insertFirst(f,1); insertFirst(f,4); insertFirst(f,2); insertFirst(f,3); insertFirst(f,3);
    output(f);
    function(f);
    output(f);

    node * s = NULL;
    for (int i = 1; i < 5; i++) insertFirst(s,i);

    output(s);
    function(s);
    output(s);

    node * t = NULL;
    insertFirst(t,1); insertFirst(t,3); insertFirst(t,2); insertFirst(t,4); 
    output(t);
    function(t);
    output(t);
}

int main() {
    
    test();

    return 0;

}