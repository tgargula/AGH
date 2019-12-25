/*
4.Dana jest tablica int t[MAX][MAX] wypełniona liczbami naturalnymi. Proszę napisać funkcję która zwraca wiersz i kolumnę dowolnego elementu, 
dla którego iloraz sumy elementów w kolumnie w którym leży element do sumy elementów wiersza w którym leży element jest największa
*/

#include<bits/stdc++.h>
using namespace std;

const int MAX = 13;
int Tab[MAX][MAX];

struct coordinates {
    int w; 
    int k;
};

void RandomArray() {
    srand(time(NULL));
    for(int w = 0; w < MAX; w++) {
        for(int k = 0; k < MAX; k++) {
            srand(rand());
            Tab[w][k] = rand() % MAX + 1;
        }
    }
}

void PrintArray() {
    for(int w = 0; w < MAX; w++) {
        for(int k = 0; k < MAX; k++) {
            cout << Tab[w][k] << '\t';
        }
        cout << '\n';
    }
}

coordinates Solver() {
    int kmax = 0, wmin = INT32_MAX, ksum, wsum;
    coordinates crd;
    for (int i = 0; i < MAX; i++) {
        ksum = wsum = 0;
        for (int j = 0; j < MAX; j++) {
            wsum += Tab[i][j]; ksum += Tab[j][i];
            //cout << "i= " << i << "\t" << "j= " << j << '\t' << "wsum= " << wsum << '\t' << "ksum= " << ksum << '\t' << endl;
        }
        if(kmax < ksum) {kmax = ksum; crd.k = i;}
        if(wmin > wsum) {wmin = wsum; crd.w = i;}
        //cout << "crd.k= " << crd.k << '\t' << "crd.w= " << crd.w << endl;
    }
    return crd;
}

int main() {
    // int Tab[MAX][MAX];
    RandomArray();
    //PrintArray();
    coordinates crd = Solver();
    cout << "w = " << crd.w << " k = " << crd.k << endl;
}