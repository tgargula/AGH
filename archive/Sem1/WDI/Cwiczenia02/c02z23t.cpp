// Program wyznacza najmniejszą podstawę 2-16, taką że podane liczby są różnocyfrowe. Jeśli nie istnieje taka podstawa 2-16, to informuje o tym

#include <iostream>

using namespace std;

int a, b;
int p, temp;
bool digit[16];
bool flag;

int main() {
    cin >> a >> b;
    for(p = 2; p <= 16; p++) {
        for(int i = 0; i < 10; i++) digit[i] = false;

        temp = a;
        while(temp > 0) {
            digit[temp%p] = true;
            temp /= p;
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