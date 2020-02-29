/*
11. Proszę napisać funkcję, która otrzymując jako parametr wskazujący
na początek listy jednokierunkowej, usuwa z niej wszystkie elementy,
w których wartość klucza w zapisie trójkowym ma większą ilość jedynek
niż dwójek.
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

bool condition (int x) {
    int one, two;
    one = two = 0;
    while (x > 0) {
        if (x %3 == 2) ++two;
        else if (x %3 == 1) ++one;
        x /= 3;
    }

    return two < one;
}

void deleteNode (node * prev) {
    node * r = prev->next;
    prev->next = prev->next->next;
    delete r;
}

void deleteFirst (node *&f) {
    node * r = f;
    f = f->next;
    delete r;
}

void function (node *&F) {
    node * prev = NULL;
    node * f = F;

    while (f != NULL) {
        if (condition(f->v)) {
            if (prev == NULL) { F = F->next; deleteFirst(f); }
            else deleteNode(prev);
        }
        prev = f;
        f = f->next;
    }
}

void test() {
    node * f = NULL;
    insertFirst(f,2); insertFirst(f,1); insertFirst(f,113); insertFirst(f,13);
    output(f);
    function(f);
    output(f);
}

int main() {

    test();

    return 0;
}