/*
5. Liczby naturalne reprezentowane jak poprzednim zadaniu.
Proszę napisać funkcję dodającą dwie takie liczby.
W wyniku dodawania dwóch liczb powinna powstać nowa lista.
*/

#include <iostream>

using namespace std;

struct node {
    int v;
    node * next;
};

void insertNumber (node *&f, int x) {
    do {
        node * r = new node;
        r->v = x % 10;
        x /= 10;
        r->next = f;
        f = r;
    } while (x > 0);
}

void output (node * f) {
    while(f != NULL) {
        cout << f->v;
        f = f->next;
    }
    cout << " ";
}

node * reverseList (node * head) {
    if (head == NULL or head->next == NULL) return head;
    
    node * prev = head;
    node * curr = head->next;
    node * foll = head->next;

    prev->next = NULL;

    while (curr != NULL) {
        foll = foll->next;
        curr->next = prev;
        prev = curr;
        curr = foll;
    }

    return prev;
}

node * sum (node * f1, node * f2) {
    if (f1 == NULL) return f2;
    if (f2 == NULL) return f1;

    node * rev1 = reverseList(f1);
    node * rev2 = reverseList(f2);
    node * REVSUM = new node;
    node * curr = REVSUM;
    node * prev = NULL;
    short p = 0;

    while (rev1 != NULL and rev2 != NULL) {
        curr->v = rev1->v + rev2->v + p;
        p = (curr->v / 10);
        curr->v %= 10;

        prev = curr;
        curr->next = new node;
        curr = curr->next;
        rev1 = rev1->next;
        rev2 = rev2->next;
    }
    
    if (rev1 == NULL and rev2 == NULL) {
        if (p == 0) prev->next = NULL;
        else {
            curr->v = 1;
            curr->next = NULL;
        }
    }

    else if (rev1 == NULL) {
        curr->v = rev2->v + p;
        curr->next = rev2->next;
    }

    else {
        curr->v = rev1->v + p;
        curr->next = rev1->next;
    }
    
    return reverseList(REVSUM);
}

void printSolution (node * f, node * s) {
    output(f); cout << "+ "; output(s); cout << "= "; output(sum(f,s)); cout << endl;
}

void test() {
    node * f = NULL;
    node * s = NULL;

    insertNumber(f,123); insertNumber(s,952);
    printSolution(s,f);
}

int main() {
    
    test();

    return 0;
}