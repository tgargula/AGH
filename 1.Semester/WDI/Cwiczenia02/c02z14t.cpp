// Program sprawdza, czy w liczbie występuje cyfra wynosząca tyle, co jej liczba cyfr <3

#include <iostream>

using namespace std;

int n, t, i;
bool b = false;

int main() {
    cin >> n;
    for(t = n, i = 0; t > 0; i++) t /= 10;

    while(n > 0) {
        if(n % 10 == i) b = true;
        n /= 10;
    }
    
    if(b) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}