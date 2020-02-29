/*
5. Proszę napisać funkcję, która rozdziela elementy listy wejściowej do 10 list,
według ostatniej cyfry pola val. W drugim kroku powstałe listy należy połączyć w jedną listę,
która jest posortowananiemalejąco według ostatniej cyfry pola val.
*/

#include <iostream>

using namespace std;

struct node {
    int value;
    node * next;
};

void insertFirst (node *&f, int value) {
    node * r = new node;
    r->value = value;
    r->next = f;
    f = r;
}

void output (node * f) {
    while (f != NULL) {
        cout << f->value << " ";
        f = f->next;
    }
    cout << endl;
}

node * sortByTheLastDigit (node * f) {
    node * tail[10];
    node * head[10];
    for (int i = 0; i < 10; i++) {
        head[i] = new node;
        head[i]->next = NULL;
        tail[i] = head[i];
    }

    while (f != NULL) {
        int key = f->value%10;
        tail[key]->next = f;
        f = f->next;
        tail[key] = tail[key]->next;
        tail[key]->next = NULL;
    }
    
    for (int i = 0; i < 10; i++) head[i] = head[i]->next;

    node * sortedListTail = new node;
    node * sortedListHead = sortedListTail;
    for (int i = 0; i < 10; i++) {
        if (head[i] != NULL) {
            sortedListTail->next = head[i];
            while (sortedListTail->next != NULL) sortedListTail = sortedListTail->next;
        }
    }

    return sortedListHead->next;
}

void test() {
    node * f = NULL;
    srand(time(NULL));
    for (int i = 0; i < 50; i++) {
        insertFirst(f,rand() % 100);
        srand(rand());
    }
    output(f);
    output(sortByTheLastDigit(f));
}

int main() {

    test();

    return 0;
}