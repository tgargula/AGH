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
    while(f != NULL) {
        cout << f->v << " ";
        f = f->next;
    }
    cout << endl;
}

node * sumOfPolynomials (node * f, node * s) {
    if (f == NULL) return s;
    if (s == NULL) return f;
    
    node * sum = new node;
    node * SUM = sum;
    node * sump = NULL;
    
    while (f != NULL and s != NULL) {
        sum->v = f->v + s->v;
        sum->next = new node;
        sump = sum;
        sum = sum->next;
        f = f->next;   
        s = s->next;
    }
    if(f == NULL) sump->next = s;
    else sump->next = f;

    return SUM;
}

int main() {
    node * f = NULL;
    node * s = NULL;
    insertFirst(f,1); insertFirst(f,2); insertFirst(f,3); insertFirst(f,4);
    insertFirst(s,5); insertFirst(s,6);

    output(f);
    output(s);
    output(sumOfPolynomials(f,s));

    node * a = NULL;
    insertFirst(a,4); insertFirst(a,5); insertFirst(a,7);

    output(a);
    output(sumOfPolynomials(a,a));

    return 0;
}