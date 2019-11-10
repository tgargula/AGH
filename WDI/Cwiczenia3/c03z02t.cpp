/*
2.Napisać program wczytujący dwie liczby naturalne i odpowiadający na pytanie 
czy są one zbudowane z takich samych cyfr, np. 123 i 321, 1255 i 5125, 11000 i 10001.
*/ 

#include <iostream>

using namespace std;

int n1, n2, tab1[10] = {0}, tab2[10] = {0};
bool check = true;

int main() {
    cin >> n1 >> n2;

    if(n1 != n2) {
        while(n1 > 0) {
            tab1[n1%10]++;
            n1 /= 10;
        }

        while(n2 > 0) {
            tab2[n2%10]++;
            n2 /= 10;
        }

        for(int i = 0; i < 10; i++) {
            if(tab1[i] != tab2[i]) {
                check = false;
                break;
            }
        }
    }

    if(check) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
