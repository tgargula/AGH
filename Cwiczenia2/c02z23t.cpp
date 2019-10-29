#include <iostream>

using namespace std;

int a, b;
int x[32], y[32];
int p, temp, j;
bool digit[16];
bool flag;

int main() {
    cin >> a >> b;
    for(p = 2; p <= 16; p++) {
        for(int i = 0; i < 10; i++) digit[i] = false;

        temp = a;
        while(temp > 0) {
            digit[temp%p] = true;
            temp /= 10;
        }
        
        temp = b;
        flag = true;
        while(temp > 0) {
            if(digit[temp%p]) {
                flag = false;
                break;
            }
            else temp /= p;
        }
        if(flag) break;
    }
    if(flag) cout << p << endl;
    else cout << "Such a base does not exist" << endl;


    return 0;
}