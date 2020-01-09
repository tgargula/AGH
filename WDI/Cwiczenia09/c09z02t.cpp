// Funkcje do implementacji tablicy rzadkiej

#include <iostream>

using namespace std;

struct node {
    int value;
    int address;
    node * next;
};

const int defaultValue = 0;

void init (node *&tab) {

}

int value (node * sparseTable, int address, int value) {
    while (sparseTable != NULL and sparseTable->address < address) sparseTable = sparseTable->next;
    return (sparseTable != NULL and sparseTable->address == address) ? sparseTable->value : defaultValue;
}

void set (node *&sparseTable, int address, int value) {
    node * prev = NULL;
    node * curr = sparseTable;
    while (curr != NULL and curr->address < address) {
        prev = curr;
        curr = curr->next;
    }

    node * r = new node;
    r->value = value;
    r->address = address;
    if (prev == NULL) {
        r->next = sparseTable;
        sparseTable = r;
    }
    else {
        r->next = curr;
        prev->next = r;
    }
}

void test() {
    
}

int main() {

    return 0;
}