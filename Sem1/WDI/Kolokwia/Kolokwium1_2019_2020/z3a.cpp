#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 8;

struct cords {
    int x, y, summ;
};

void randomIntArray(int t[N][N]) {
    srand((unsigned)time(NULL));
    for(int x = 0; x < N*N; x++) {
        srand((unsigned)rand());
        int r = (int)((rand() % 3) -1);
        t[x/N][x%N] = r;
    }
    t[0][0] = -1;
}

void printIntArray(int t[N][N]) {
    for(int x = 0; x < N*N; x++) {
        cout << t[x/N][x%N] << '\t';
        if(x%N == N-1) cout << endl;
    }
}

void printCords(cords tab[N], int n=0) {
    while(n < N) {
        cout << tab[n].x << " " << tab[n].y << " " << tab[n].summ << endl;
        n++;
    }
}

bool isPossiblePutCords(int y1, int y2, int yC) {
    if(abs(y1-yC) > 2 and abs(y2-yC) > 2) return true;
    return false;
}

bool isPossibleToArrangeRecursive(int t[N][N], int sum, int which, int x, int y1, int y2, bool &isPossible, cords tab[N]) {
    if(which == N and sum == 0 and !isPossible) {
        isPossible = true;
        printCords(tab);
    }
    if(isPossible) return isPossible;
    if(x >= N) return false;

    for(int yC = 0; yC < N; yC++) {
        if(isPossiblePutCords(y1, y2, yC)) {
            sum += t[x+1][yC];
            tab[x+1].x = x+1; tab[x+1].y = yC; tab[x+1].summ = sum;
            isPossibleToArrangeRecursive(t, sum, which+1, x+1, yC, y1, isPossible, tab);
            // cout << x+1 << " " << yC << endl;
        }
    }
}

bool isPossibleToArrangeStart(int t[N][N]) {
    bool isPossible = false; cords tab[N];
    for(int i = 0; i < N and !isPossible; i++) {
        tab[0].x = 0; tab[0].y = i; tab[0].summ = t[0][i];
        isPossibleToArrangeRecursive(t, t[0][i], 1, 0, i, i, isPossible, tab);
    }
    return isPossible;
}

int main() {
    int t[N][N]; // int t2[1]; t2[0] = -1; cout << t2[0] << endl;
    randomIntArray(t);
    printIntArray(t);
    if(isPossibleToArrangeStart(t)) cout << "OK" << endl;
    return 0;
}