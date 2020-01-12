#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 30;

struct cords {
    int x, y, summ;
};

void randomIntArray(int t[N][N]) {
    srand((unsigned)time(NULL));
    for(int x = 0; x < N*N; x++) {
        srand((unsigned)rand());
        int r = (int)((rand() % 351) -175);
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

bool isPossible(int t[N][N], int which, int x, int y1, int sum, bool &isPoss, cords tab[N]) {
    if(which == N and x == N-1 and sum == 0) {
        cout << "critical sum " << sum << endl;
        isPoss = true;
        printCords(tab);
    }
    if(isPoss) return isPoss;

    for(int i = 0; i < N; i++) {
        if(x+1 < N and abs(y1-i) > 1) {
            int sum2 = sum;
            sum2 += t[x+1][i];
            tab[x+1].x = x+1; tab[x+1].y = i; tab[x+1].summ = sum2;
            isPossible(t, which+1, x+1, i, sum2, isPoss, tab);
        }
    }
    return isPoss;
}

int main() {
    int t[N][N]; cords tab[N];
    randomIntArray(t);
    printIntArray(t);
    for(int i = 0; i < N; i++) {
        cout << i << endl;
        bool isPoss = false;
        tab[0].x = 0; tab[0].y = i; tab[0].summ = t[0][i];
        if(isPossible(t, 1, 0, i, t[0][i], isPoss, tab)) cout << "OK" << endl;
    }
    return 0;
}