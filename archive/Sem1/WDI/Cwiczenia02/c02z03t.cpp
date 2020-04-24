/*
3. Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie,
czy liczba naturalna jest palindromem, a następnie czy jest palindromem w systemie
dwójkowym.
*/

#include <iostream>
#include <cmath>

using namespace std;

int rev (int n) {       // Funkcja odwracająca kolejność cyfr
    int t=0;
    while (n>0) { 
        t*=10;
        t+=n%10;
        n/=10;
    }
    return t;
}

int main() {
    int n;
    cin >> n;

    if(rev(n)==n) cout << "YES" << endl;
    else cout << "NO" << endl;

    int bin[32];
    int i=0;
    bool con = true;
    while (n>0) {       // dec2bin
        bin[i] = n%2;
        n /= 2;
        i++;
    }

    // for(int j=i-1; j>=0; j--) cout << bin[j];        //TEST 1 - wypisuje liczbę w postaci binarnej
    // cout << endl;
    for(int j=0; j<i; j++) {

        // cout << bin[j] << " " << bin[i-j-1] << endl; //TEST 2 - wypisuje sprawdzane pary
        
        if(bin[j] != bin[i-j-1]) {
            con = false;
            break;
        }   
    }

    if(con) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
