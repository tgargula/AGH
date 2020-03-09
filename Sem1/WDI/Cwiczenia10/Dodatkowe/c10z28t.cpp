/*
28. Lista reprezentuje wielomian o współczynnikach całkowitych.
Elementy w liście ułożone są według rosnących potęg. Proszę napisać
funkcję  obliczającą różnicę dwóch dowolnych wielomianów. Wielomiany
reprezentowane są przez wyżej opisane listy. Procedura powinna zwracać
wskaźnik do nowo utworzonej listy  reprezentującej wielomian wynikowy.
Listy wejściowe powinny pozostać niezmienione.
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

node * sumOfPolynomials (node * f, node * s) {
    if (f == NULL) return s;
    if (s == NULL) return f;
    
    node * SUM = new node;
    node * curr = SUM;
    node * prev = NULL;
    
    while (f != NULL and s != NULL) {
        curr->v = f->v + s->v;
        //curr->next = new node;
        prev = curr;
        curr = curr->next;
        f = f->next;   
        s = s->next;
    }
    if (f == NULL) prev->next = s;
    else prev->next = f;

    return SUM;
}

void test() {
    node * f = NULL;
    node * s = NULL;
    insertFirst(f,1); insertFirst(f,2); insertFirst(f,3); insertFirst(f,4);
    insertFirst(s,5); insertFirst(s,6);

    output(f);
    output(s);
    output(sumOfPolynomials(f,s));
    output(f);
    output(s);

    node * a = NULL;
    insertFirst(a,4); insertFirst(a,5); insertFirst(a,7);

    output(a);
    output(sumOfPolynomials(a,a));

}

int main() {
    
    test();

    return 0;
}