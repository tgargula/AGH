// 9. Rekurencyjne obliczanie wyznacznika z macierzy (treść oczywista)

#include <iostream>
#include <ctime>

using namespace std;

const int MAX = 11;

inline short sign (int mainRow) { return mainRow %2 == 0 ? 1 : -1; }

int determinantOfTheMatrix (int det[MAX][MAX], int size) {
    int mainDeterminant = 0;
    if (size == 1) return det[0][0];

    for (int mainRow = 0; mainRow < size; mainRow++) {
        int newDet[MAX][MAX];
        int mainI, mainJ, newI, newJ; mainI = newI = 0;
        while (mainI < size) {
            newJ = 0; mainJ = 1;
            if (mainI == mainRow) { mainI++; continue; }
            while (mainJ < size) {
                newDet[newI][newJ] = det[mainI][mainJ];
                mainJ++; newJ++;
            }
            mainI++; newI++;
        }

        mainDeterminant += sign(mainRow) * det[mainRow][0] * determinantOfTheMatrix(newDet,size-1);
    }

    return mainDeterminant;
}

void insertRandomMatrix (int det[MAX][MAX], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            srand(rand());
            det[i][j] = rand() % 21 - 10;
            cout << det[i][j] << "\t";
        }
        cout << endl;
    }

    clock_t time;
    time = clock();
    cout << "det = " << determinantOfTheMatrix(det,size) << " (" << (float)(clock() - time)/CLOCKS_PER_SEC << " seconds)\n\n";
}

void test() {
    int det[MAX][MAX];

    for(int size = 2; size <= 11; size++) insertRandomMatrix(det,size);
    
    int size = 5;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) det[i][j] = 1;
            else det[i][j] = 0;
            cout << det[i][j] << " ";
        }
        cout << endl;
    }
    cout << "det = " << determinantOfTheMatrix(det,size) << "\n\n";
}

int main() {
    
    test();

    return 0;
}