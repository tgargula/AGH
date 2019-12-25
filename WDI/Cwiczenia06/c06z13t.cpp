/*
A problem of Hanoi Towers
F(n) = 2*F(n-1) + 1
*/ 

#include <iostream>

using namespace std;

int HanoiTowers(int n, int sum) {
    if(n == 0) return sum;
    return HanoiTowers(n-1, 2*sum+1);
}

int main() {
    int n;
    cin >> n;
    cout << HanoiTowers(n, 0) << endl;
    return 0;
}