/*
8.Napisać program wypełniający tablicę int t[MAX] liczbami naturalnymi 1-1000 
i sprawdzający czy istnieje element tablicy zawierający wyłącznie cyfry nieparzyste.

ten balagan z komentarzami to "dla wygody" jakby ktos kiedys chcial patrzec jak program dziala
*/

#include<bits/stdc++.h>
using namespace std;

const int MAX = 5;

main() {
    int t[MAX]; bool flag = true;
    srand(time(0));
    for(int i = 0; i < MAX; i ++) {
        t[i] = rand() % 1000 + 1;
        srand(rand());
    }

    for(int i = 0; i < MAX; i ++) {
        flag = true;
        cout << "i = " << t[i] << endl;
        while(t[i] > 0 && flag) {
            if(t[i] % 2 == 0) {
                flag = false;
                break;
            }
            t[i] = t[i] / 10;
        }
        if(flag == true) {
            cout << "OK"; return 0;
        }
    }
    cout << "NOT"; return 0;
}