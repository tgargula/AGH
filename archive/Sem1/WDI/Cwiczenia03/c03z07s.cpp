/*
7.Napisać program wypełniający tablicę int t[MAX] liczbami naturalnymi 1-1000 
i sprawdzającyczy każdy element tablicy zawiera co najmniej jedną cyfrę nieparzystą.

ten balagan z komentarzami to "dla wygody" jakby ktos kiedys chcial patrzec jak program dziala
*/

#include<bits/stdc++.h>
using namespace std;

const int MAX = 20;

main() {
    int t[MAX]; bool flag = true;
    srand(time(0));
    for(int i = 0; i < MAX; i ++) {
        t[i] = rand() % 1000 + 1;
        srand(rand());
    }

    for(int i = 0; i < MAX; i ++) {
        flag = true;
        //cout << "i = " << t[i] << endl;
        while(t[i] > 0 && flag) {
            if(t[i] % 2 == 1 ) {
                flag = false;
                break;
            }
            t[i] = t[i] / 10;
        }
        if(flag == true) {
            cout << "NOT"; return 0;
        }
    }
    cout << "OK"; return 0;
}