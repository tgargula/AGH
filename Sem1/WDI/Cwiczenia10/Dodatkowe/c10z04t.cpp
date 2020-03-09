/*
4. Dana jest niepusta lista reprezentująca liczbę naturalną.
Kolejne elementy listy przechowują kolejne cyfry.
Proszę napisać funkcję zwiększającą taką liczbę o 1.
*/

#include <iostream>

using namespace std;

struct node {
    int v;
    node * next;
};

node * reverseList (node * head) {
    if(head == NULL or head->next == NULL) return head;
    
    node * prev = head;
    node * curr = head->next;
    node * foll = head->next;

    prev->next = NULL;

    while(curr != NULL) {
        foll = foll->next;
        curr->next = prev;
        prev = curr;
        curr = foll;
    }

    return prev;
}

void output (node * f) {
    while (f != NULL) {
        cout << f->v;
        f = f->next;
    }
    cout << endl;
}

void insertLast (node *&f, int x) {
    node * r = new node;
    r->v = x;
    r->next = NULL;

    if (f == NULL) { f = r; return; }

    node * prev = f;
    node * curr = f;
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
    }
    
    prev->next = r;
}

void addOne (node *&f) {
    node * one = new node;
    one->v = 1;
    one->next = NULL;

    if (f == NULL) {    
        f = one;
        return;
    }

    node * REV = reverseList(f);
    node * rev = REV;
    node * prev = NULL;
    rev->v++;
    while (rev != NULL and rev->v == 10) {
        rev->v = 0;
        prev = rev;
        rev = rev->next;
        if (rev != NULL) rev->v++;
    }
    
    if (rev == NULL) {
        prev->v = 0;
        prev->next = one;
    }

    f = reverseList(REV);
}

void test() {
    node * f = NULL;

    for (int i = 1; i <= 9; i++) insertLast(f,i);

    output(f);
    addOne(f); output(f);
    addOne(f); output(f);

    node * o = NULL;

    output(o);
    addOne(o); output(o);

    node * s = NULL;

    insertLast(s,9); insertLast(s,8);

    output(s);
    addOne(s); output(s);
    addOne(s); output(s);
}

int main() {

    test();

    return 0;
}