/*
Autor:
1. Napisać program wypisujący elementy ciągu Fibonacciego mniejsze od miliona.
*/
#include <iostream>

using namespace std;

const int s = 1000000;

int main() {
    int a=1,b=1,c;
    while(a<s) {
        cout << a << " ";
        c = a+b;
        a = b;
        b = c;
    }

    return 0;
}