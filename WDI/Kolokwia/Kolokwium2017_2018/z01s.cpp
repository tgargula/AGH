#include <iostream>

using namespace std;

const int N = 9;

int Kawalki(int t[N]) {
    int sumaBazowa = 0, sumaCzesciowa = 0, kawalki = 1;
    for(int i = 0; i < N; i++) {
        sumaBazowa += t[i];
        cout << "sumaBazowa " << sumaBazowa << endl;
        for(int j = i+1; j < N; j++) {
            sumaCzesciowa += t[j]; cout << "sumaCzesciowa " << sumaCzesciowa << endl;
            if(sumaCzesciowa == sumaBazowa) { 
                kawalki++; sumaCzesciowa = 0; cout << "kawalki " << kawalki << endl;
            }
            if(sumaCzesciowa > sumaBazowa) {
                sumaCzesciowa = 0;
                kawalki = 1;
                cout << "break" << endl; 
                break; 
            }
            if(j == N - 1) {
                return kawalki;
            }
        }
    }
    if(kawalki == 1) {
        return 0;
    }
}

int main () {
    int t[N] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    // int t[N] = {1, 2, 3, 1, 5, 2, 2, 2, 6};
    cout << Kawalki(t);
    return 0;
}