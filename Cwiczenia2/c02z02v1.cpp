#include <iostream>

using namespace std;

int main() {
    int n,s=1,i=0;
    cin >> n;

    while(s<n) {
        s = i*i + i + 1;
        i++;
    }

    if(s == n) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}