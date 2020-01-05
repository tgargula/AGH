/*
27. Proszę napisać funkcję, która rozdziela listę na dwie listy.
Pierwsza powinna zawierać klucze parzyste dodatnie, drugi klucze
nieparzyste ujemne, pozostałe  elementy  należy  usunąć  z  pamięci.
Do  funkcji  należy  przekazać wskaźniki  na  listę  z  danymi  oraz
wskaźniki  na  listy  wynikowe.  Funkcja powinna zwrócić liczbę
usuniętych elementów.
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

void addToList (node *&f, node *&a) {
    node * r = f;
    f = f->next;
    r->next = a;
    a = r;
}

void deleteFirst (node *&f) {
    node * r = f;
    f = f->next;
    delete r;
}

void function (node *&f, node *&a, node *&b) {
    while (f != NULL) {
        if (f->v > 0 and f->v %2 == 0) addToList(f,a);
        else if (f->v < 0 and -(f->v) %2 == 1) addToList(f,b);
        else deleteFirst(f);
    }
}

void test() {
    node * f = NULL;
    for (int i = -15; i <= 25; i++) insertFirst(f,i);

    output(f);

    node * a = NULL;
    node * b = NULL;
    function(f,a,b);

    output(a);
    output(b);
    output(f);

}

int main() {
    
    test();

    return 0;
}