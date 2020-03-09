#include <iostream>
using namespace std;

int main() {
    short x = -1, y = 0;
    while( abs(x) - abs(y) >= 1) {x--; y++;}
    cout << x << " " << y << endl;
}