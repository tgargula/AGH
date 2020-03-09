// Program sprawdza, czy cyfry liczby n stanowią ciąg rosnący

#include <iostream>

using namespace std;

int n, t1, t2;
bool flag = true;

int main() {
    cin >> n;
    t1 = 10;
    if(n < 10) flag = false;
    else
        while(n > 0) {
            t2 = n % 10;
            n /= 10;
            if(t2 >= t1) flag = false;
            t1 = t2;
        }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}