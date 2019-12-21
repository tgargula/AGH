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
        cout << m->v << " ";
        m = m->next;
    }
    cout << endl;
}

void deleteEverySecond (node *f) {
    int ctr = 1;
    node *r = f;
    while(r->next->next != NULL) {
        node *h = r->next;
        r->next = r->next->next;
        delete h;
        r = r->next;
    }
}

int main() {
    node *f = new node;

    for(int i = 1; i<=15; i++) insertFirst(f,i);

    output(f);

    deleteEverySecond(f);

    output(f);

}