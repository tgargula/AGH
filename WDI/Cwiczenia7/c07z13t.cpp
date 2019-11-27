#include <iostream>

using namespace std;

void HanoiTowers (int n, char a, char b, char c) {
    if(n>0) {
        HanoiTowers(n-1,a,c,b);
        cout << a << " -> " << c << endl;
        HanoiTowers(n-1,b,a,c);
    }
}

int main() {
    int n; cin >> n;
    HanoiTowers(n,'A','B','C');
    return 0;
}