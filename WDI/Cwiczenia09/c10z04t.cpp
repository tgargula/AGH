#include <iostream>

using namespace std;

struct node {
    int v;
    node *next;
};

void insertFirst (node *&f, int x) {
    node *r = new node;
    r->v = x;
    r->next = f;
    f = r;
}

void output (node *f) {
    while(f->next != NULL) {
        cout << f->v << endl;
        f = f->next;
    }
}


int main() {
    node *f = new node;

    for(int i = 0; i<10; i++) insertFirst(f,i);

    output(f);

    return 0;
}