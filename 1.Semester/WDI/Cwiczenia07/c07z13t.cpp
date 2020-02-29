#include <iostream>

using namespace std;

int HanoiTowers (int n, char a, char b, char c, int &sum) {
    if(n>0) {
        HanoiTowers(n-1,a,c,b, sum);
        cout << a << " -> " << c << endl; sum++;
        HanoiTowers(n-1,b,a,c, sum);
    }
    return sum;
}

int main() {
    int n, sum = 0; cin >> n;
    cout << HanoiTowers(n,'A','B','C', sum) << endl;
    return 0;
}