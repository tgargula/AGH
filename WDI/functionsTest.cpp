#include <iostream>
#include <string>
#include "functions.hpp"

using namespace std;

// void RandomIntArrayExperimental(int Array[], int range = 100) {
//     srand(time(NULL));
//     for(int i = 0; i < *(&Array + 1) - Array; i++) {
//         srand(rand()); 
//         Array[i] = rand() % range;
//     }
// }

// void PrintIntArrayExperimental(int Array[]) {
//     for(int i = 0; i < *(&Array + 1) - Array; i++) {
//         cout << Array[i] << " ";
//     }
//     cout << endl;
// }

int main() {
    node *first = createListWithCycle(10, 5);
    cout << first->value << endl;
    // printListElements(first);
    // if(hasListCycle(first)) cout << "has cycle" << endl;
    cout << countElemsBeforeCycle(first) << endl;
    cout << countElemsInCycle(first) << endl;
    // node *first = createList(10);
    // first->value = NULL;
    // // cout << first->value << endl;
    // printListElements(first, true);
    // first->value = 15;
    // printListElements(first, true);
    // node *first = createCycleList(5);
    // node *first = createListWithCycle(15);
    // if(hasListCycle(first)) cout << "has Cycle" << endl;
    // cout << listLength(first) << endl;
    // printListElements(first);
    // int t[5]; cout << *(&t + 1) - t << endl;
    // RandomIntArrayExperimental(t, 10);
    // PrintIntArrayExperimental(t);
    // singleNodePointer *first = createList();
    // singleNodePointer *first = createCycleList(100);
    // printListElements(first);
    // insertLast(first, 999);
    // testInsertLast(first, 111);
    // printListElements(first);
    // deleteLast(first);
    // deleteByValue(first, 5);
    // insertByOrder(first, 1, 1555);
    // deleteByOrder(first, 1);
    // first = listRverse(first);
    // printListElements(first);
    // connectLastElementToFirst(first);
    // printListElements(first, true);

    // cout << FindFibonacciNuberRecursive(46) << endl;
}