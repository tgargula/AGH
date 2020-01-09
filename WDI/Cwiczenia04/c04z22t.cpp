#include <iostream>

using namespace std;

const int N = 5;

inline void sumUp (int counter, int MAX, int currentMaxRow, int i) {
    if (counter > MAX) { MAX = counter; currentMaxRow = i; }
}

int theLongestConsistentSubsequence (int t[N][N]) {
    int MAX = 0;
    int currentMaxRow = -1;
    
    for (int i = 0; i < N; i++) {
        int curr = t[i][0];
        int counter = 1;
        for (int j = 1; j < N; j++) {
            if (t[i][j] == curr) counter++;
            else {
                sumUp(counter,MAX,currentMaxRow,i);
                counter = 1;
                curr = t[i][j];
            }
        }

        sumUp(counter,MAX,currentMaxRow,i);
    }

    return currentMaxRow;
}

void test() {
    int t[N][N];
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            srand(rand());
            t[i][j] = rand() % 3;
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    cout << theLongestConsistentSubsequence(t) << endl;
}

int main() {

    test();

    return 0;
}