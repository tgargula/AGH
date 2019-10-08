#include <iostream>

using namespace std;

const int s = 1000000;

int main() {
    int a=27,b=6,c;
    while(a<s) {
        cout << a << " ";
        c = a+b;
        a = b;
        b = c;
    }

    return 0;
}