/*
13. Proszę napisać funkcję, która otrzymując jako parametr wskazujący
na początek listy dwukierunkowej, usuwa z niej wszystkie elementy,
w których wartość klucza w zapisie binarnym ma nieparzystą ilość jedynek.
*/

#include <iostream>

using namespace std;

struct node {
    int v;
    node * next;
    node * prev;
};

void insertFirst (node *&f, int x) {
    node * r = new node;
    r->v = x;
    r->next = f;
    r->prev = NULL;
    if (f != NULL) f->prev = r;
    f = r;
}

void output (node * f) {
    while (f != NULL) {
        cout << f->v << " ";
        f = f->next;
    }
    cout << endl;
}

bool con (int x) {
    int ctr = 0;
    while (x > 0) {
        if (x %2 == 1) ctr++;
        x /= 2;
    }
    return ctr %2 == 1 ? true : false;
}

void function (node *&f) {
    node * curr = f;
    while (curr != NULL) {
        if (con(curr->v)) {
            node * r = curr;

            if (curr->next != NULL) curr->next->prev = curr->prev;
            if (curr->prev != NULL) curr->prev->next = curr->next;

            curr = curr->prev;
            delete r;
        }
        curr = curr->next;
    }
}

int main() {
    node * f = NULL;
    for(int i = 0; i <= 10; i++) insertFirst(f,i); 
    output(f);
    function(f);
    output(f);
    
    return 0;
}