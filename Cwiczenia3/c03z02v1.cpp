/*
2.Napisać program wczytujący dwie liczby naturalne 
i odpowiadający na pytanie czy są one zbudowane z takich samych cyfr, np. 123 i 321, 1255 i 5125, 11000 i 10001.

mam wrazenie ze drobna niescislosc polecenia / przykladu:
moga byc zbudowane z tych samych cyfr ale roznej dlugosci 10 i 10000110101

ten program sprawdza czy liczby skladaja sie z tej samej liczby takich odpowiednich cyfr
*/
#include<bits/stdc++.h>
using namespace std;

main() {
    int a, b;
    cin >> a >> b;
    if(a == b) {
        cout << "The same"; return 0;
    }
    vector<int> A;
    vector<int> B;
    while(a != 0) {
        A.push_back(a % 10); a /= 10;
    }
    while(b != 0) {
        B.push_back(b % 10); b /= 10;
    }
    sort(A.begin() , A.end());
    sort(B.begin() , B.end());
    if(A.size() != B.size()) {
        cout << "Not the same"; return 0;
    }
    for(int i = 0; i < A.size(); i++) {
        if(A[i] != B[i]) {
            cout << "Not the same"; return 0;
        }
    }
    cout << "The same"; return 0;
}