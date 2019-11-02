// Program sprawdza, czy cyfra jedności liczby n jest unikalna

#include <iostream>

using namespace std;

int n, c;
bool b = true;

int main() {
    cin >> n;
    c = n % 10;

    while(n > 0) {
        n /= 10;
        if(n % 10 == c) {
            b = false;
            break;
        }
    }

    if(b) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}