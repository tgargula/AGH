#include <iostream>

using namespace std;

const int MAX = 10;

void RandomArray(int t[MAX][MAX]) {
    srand(time(NULL));
    for(int i = 0; i < MAX; i++) {
        t[i][0] = rand() % 10 + 1;
        for(int j = 1; j < MAX; j++) t[i][j] = rand() % 10 + t[i][j-1];
    }
}

void PrintMatrix(int t[MAX][MAX]) {
    cout << "i \\ j\t\t";
    for(int i = 0; i < MAX; i++) cout << i << "\t";
    cout << endl << "\t";
    for(int i = 0; i <= MAX; i++) cout << "--------";
    cout << endl;
    for(int i = 0; i < MAX; i++) {
        cout << i << "\t|\t";
        for(int j = 0; j < MAX; j++) {
            cout << t[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void Rewrite (int tab1[MAX][MAX], int tab2[MAX*MAX]) {
    int i[MAX];
    bool 
    for(int j = 0; j < MAX; j++) i[j] = 0;

    for(int j = 0; j < MAX; j++) {
        int m = INT32_MAX;
        for(int k = 0; k < MAX; k++) {
            if(tab1[i[j]][k] < m) { m = tab1[i[j]][k]; } // Muszę dokończyć
        }
    }
}


int main() {
    int tab1[MAX][MAX];
    int tab2[MAX*MAX];

    RandomArray(tab1);
    PrintMatrix(tab1);

    Rewrite(tab1, tab2);
    

    return 0;
}