#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
};

int countElemsInCycle(node *first) {
    if(first == NULL) return 0;
    if(first->next == first) return 1;
    node *fasterNode = first->next;
    while(fasterNode != first) {
        fasterNode = fasterNode->next;
        fasterNode = fasterNode->next;      //doesn't check if next = null becouse list has cycle
        first = first->next;
    }
    fasterNode = fasterNode->next;
    int cycleLength = 1;
    while(fasterNode != first) {
        fasterNode = fasterNode->next;
        cycleLength++;
    }
    return cycleLength;
}

int cycleListReverseWithCount(node *first) {
    if(first == NULL or first->next == first) return 0;
    node *currentNode = first->next;
    if(currentNode->next == first) return 0;
    if(currentNode->next == currentNode) return 1;
    node *nextNode = currentNode->next;
    int result = 0;
    while(nextNode != NULL) {
        currentNode->next == first;
        first = currentNode;
        currentNode = nextNode;
        nextNode = nextNode->next;
        result++;
    }
    currentNode->next = first;
    return result;
}


int main () {

}