// 9. Rekurencyjne obliczanie wyznacznika z macierzy (treść oczywista)

#include <iostream>
#include <ctime>

using namespace std;

const int MAX = 11;

inline short sign (int selectedRow) { return selectedRow %2 == 0 ? 1 : -1; }

int determinantOfTheMatrix (int matrix[MAX][MAX], int size) {
    int determinant = 0;
    if (size == 1) return matrix[0][0];

    // Due to the Laplace expansion along the 0th column
    for (int selectedRow = 0; selectedRow < size; selectedRow++) {
        int newMatrix[MAX][MAX];
        for (int i = 0, newI = 0; i < size; i++, newI++) {
            if (i == selectedRow) { newI--; continue; }
            for (int j = 1; j < size; j++) newMatrix[newI][j-1] = matrix[i][j];
        }

        determinant += sign(selectedRow) * matrix[selectedRow][0] * determinantOfTheMatrix(newMatrix,size-1);
    }

    return determinant;
}

void insertRandomMatrix (int matrix[MAX][MAX], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            srand(rand());
            matrix[i][j] = rand() % 11 - 5;
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    clock_t time;
    time = clock();
    cout << "det = " << determinantOfTheMatrix(matrix,size) << " (" << (float)(clock() - time)/CLOCKS_PER_SEC << " seconds)\n\n";
}

void test() {
    int matrix[MAX][MAX];

    for(int size = 2; size <= 11; size++) insertRandomMatrix(matrix,size);
    
    int size = 5;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) matrix[i][j] = 1;
            else matrix[i][j] = 0;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "det = " << determinantOfTheMatrix(matrix,size) << "\n\n";
}

int main() {
    
    test();

    return 0;
}