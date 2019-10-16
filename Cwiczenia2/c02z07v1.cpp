#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int a=sqrt(n); a>=1; a--)
        if(n%a == 0) {
            cout << n << "=" << a << "*" << n/a << endl;
            return 0;
        }

    // cout << n << "=" << 1 << "*" << n << endl;

    return 0;
}