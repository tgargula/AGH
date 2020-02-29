/// Implementacja zbioru liczb naturalnych
/// Funkcja belong
/// Funkcje dodające element do zbioru (od tyłu i od przodu)
/// Funkcje usuwające element ze zbioru (od tyłu, od przodu i po wartości)
/// Dodatkowo - dodawanie i usuwanie wartownika oraz wypisywanie

#include <iostream>

using namespace std;

struct node {
    int v;
    node *next;
};

bool belong (node *f, int x) {
    if( f == NULL ) return false;

    while( f->next != NULL ) {
        if( f->v == x) return true;
        f = f -> next;
    }

    if( f->v == x ) return true;

    return false;
}

void insertLast (node *&f, int x) {
    node *r = new node;
    r->v = x;
    r->next = NULL;
    node *p = f;

    node *last = NULL;
    while(p != NULL) {
        last = p;
        p = p->next;
    }
    if(last != NULL) last->next = r;
    else f = r;
}


void insertFirst (node *&f, int x) {
    node *r = new node;
    r->v = x;
    r->next = f;
    f = r;
}

void deleteLast (node *&f) {
    if ( f == NULL ) return;    // lista pusta
    if ( f->next == NULL ) {    // lista 1-elementowa
        delete f;
        f = NULL;
        return;
    }

    node *p, *q, *r;
    while ( p != NULL ) {
        r = q;
        q = p;
        p = p->next;
    }
    
    r->next = NULL;
    delete q;
}

void deleteFirst (node *&f) {
    node *tmp = f;
    f = f -> next;
    delete tmp;     //używa się tego po to, żeby zwolnić pamięć
}

void deleteValue (node *&f, int x) {
    if ( f == NULL ) return;
    node *p = f;
    node *prev = NULL;
    while ( p != NULL and prev->v != x ) { // najpierw się wykonuje w C++ pierwszy warunek
        prev = p;
        p = p->next;
    }
    if ( p == NULL ) return;            // nie ma wartości w liście
    if ( prev == NULL ) f = f -> next;  // usuwamy pierwszy wyraz
    else prev->next = p->next;
    delete p; 
}

void addSentinelNode (node *&f) {       // sentinel node - wartownik
    node *sentinel = new node;
    sentinel->next = f;
    f = sentinel;
}

void removeSentinelNode (node *&f) {
    node *tmp = f;
    f = f->next;
    delete tmp;
}

void output (node *f) {
    if ( f == NULL ) return;
    while ( f != NULL ) {
        cout << f->v << " ";
        f = f->next;
    }
    cout << endl;
}

int main() {
    node *f = new node;
    deleteFirst(f);

    for(int i = 0; i < 5; i++) insertFirst(f,i);
    output(f);
    deleteFirst(f);
    output(f);
    for(int j = 6; j < 11; j++) insertLast(f,j);
    output(f);

    if ( belong(f,4) ) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}