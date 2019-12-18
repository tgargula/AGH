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

void output(node *m) {
    while(m->next != NULL) {
        cout << m->v << endl;
        m = m->next;
    }
}

void reverse(node *f, node *&rev) {

    while(f->next != NULL) {
        insertFirst(rev,f->v);
        f = f->next;
    }

}

int main() {
    node *f = new node;
    for(int i = 10; i>0; i--) insertFirst(f,i);
    node *rev = new node;
    output(f);
    reverse(f,rev);
    output(rev);
    return 0;
}