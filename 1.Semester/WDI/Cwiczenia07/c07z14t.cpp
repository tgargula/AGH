#include <iostream>

using namespace std;

void showChessboard (int t[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool possible (int a, int b) {
    return a >= 0 and b >= 0 and a < 8 and b < 8;
}

bool isCheck (int t[8][8], int row, int column) {
    for (int i = 0; i < 8; i++) {
        if (t[i][column] != 0 or t[row][i]) return true;
        if (possible(row-i,column-i)) if (t[row-i][column-i] != 0) return true;
        if (possible(row-i,column+i)) if (t[row-i][column+i] != 0) return true;
        if (possible(row+i,column-i)) if (t[row+i][column-i] != 0) return true;
        if (possible(row+i,column+i)) if (t[row+i][column+i] != 0) return true;
    }
    return false;
}

void problemOf8Queens (int t[8][8], bool checked[8][8], int currentRow, int ctr) {
    if (ctr == 8) showChessboard(t);
    
    for (int j = 0; j < 8; j++) {
        if (!isCheck(t,currentRow,j)) {
            t[currentRow][j] = ++ctr;
            problemOf8Queens(t,checked,currentRow+1,ctr);
            t[currentRow][j] = 0;
            ctr--;
        }
    }
    
}

void test() {
    int t[8][8];
    bool checked[8][8];
    for (int i = 0; i < 8; i++)
        for (int j = i; j < 8; j++) {
            t[i][j] = 0;
            t[j][i] = 0;
            checked[i][j] = false;
            checked[j][i] = false;
        }
    problemOf8Queens(t,checked,0,0);
}

int main() {
    
    test();

    return 0;
}