#include <iostream>
#include "functions.hpp"

using namespace std;

// struct node {
//     int value;
//     node *next;
// };

// void deleteFirst( node *&first) {
//     if(first == NULL) return;
//     else if(first->next == NULL) {
//         delete first;
//         first = NULL;
//         return;
//     } else {
//         node *tmp = first;
//         first = first->next;
//         delete tmp;
//     }
// }

// void insertFirst(node *&first, int val) {
//     node *newFirst = new node;
//     newFirst->value = val;
//     if(first == NULL) newFirst = first;
//     else {
//         newFirst->next = first;
//         first = newFirst;
//     }
// }

node *deletedList(node *first, node *second) {
    node *deleted = new node;
    while(first != NULL and second != NULL) {
        if(first->value == second->value) {
            insertFirst(deleted, first->value);
            deleteFirst(first); deleteFirst(second);
        } else if(first->value < second->value and first->next != NULL) {
            first = first->next;
        } else if(first->value < second->value and first->next == NULL) {
            deleteFirst(second);
        } else if(first->value > second->value) deleteFirst(second);
    }
    while(first == NULL and second != NULL) {
        deleteFirst(second);
    }
    return deleted;
}

int main () {
    node *first = createList(10); node *second = createList(12);
    printListElements(first); printListElements(second);
    node *third = deletedList(first, second);
    printListElements(third);
    return 0;
}