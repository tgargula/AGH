/*
6. Dane są dwie tablice mogące pomieścić taką samą liczbę elementów:int t1[MAX][MAX];int t2[MAX2];             // MAX2 = MAX*MAX
W każdym wierszu tablicy t1 znajdują się uporządkowane rosnąco (w obrębie wiersza) liczby naturalne. 
Proszę napisać funkcję przepisującąwszystkie singletony (liczby występujące dokładnie raz)  z tablicy t1 do t2, 
tak aby liczby w tablicy t2 były uporządkowane rosnąco. 
Pozostałe elementy tablicy t2 powinny zawierać zera.
*/

#include<bits/stdc++.h>
using namespace std;

const int MAX = 50;
int t1[MAX][MAX], t2[MAX*MAX];

void SetT1andT2(int limit = 10) {                 //helper zapchaj tablice losowymi liczbami zgodnie z warunkami zadania
    for(int i = 0; i < MAX*MAX; i++) t2[i] = 0;

    srand(time(NULL));
    for(int i = 0; i < MAX; i++) {
        limit = 10 + 7*i;
        t1[i][0] = rand() % limit;
        for(int j = 1; j < MAX; ) {
            int toTab = rand() % limit + limit;
            if(toTab >= t1[i][j-1]) {
                t1[i][j] = toTab; j++; limit += 5;
            }
            srand(rand());
        }
    }
}

void PrinterT1() {              //helper wypisz t1
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            cout << t1[i][j] << " ";
        }
        cout << endl;
    }
}

void PrinterT2() {              //helper wypisz t2 - w kwadracie a nie lini
    for(int i = 0; i < MAX*MAX; i++) {
        cout << t2[i] << " ";
        if((i+1) % (MAX/2) == 0) cout << endl; 
    }
}


////Dla merge sort
void CopyArray(int B[], int A[], int n)
{
    for(int i = 0; i < n; i++)
        A[i] = B[i];
}

void BottomUpMerge(int A[], int iLeft, int iRight, int iEnd, int B[])
{
    int i = iLeft, j = iRight;
    for (int k = iLeft; k < iEnd; k++) {
        if (i < iRight && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;    
        }
    } 
}

void BottomUpMergeSort(int A[], int B[MAX], int n)
{
    for (int width = 1; width < n; width = 2 * width)
    {
        for (int i = 0; i < n; i = i + 2 * width)
        {
            BottomUpMerge(A, i, min(i+width, n), min(i+2*width, n), B);
        }
        CopyArray(B, A, n);

    }
}
/////

void Rewriter() {
    int temp[MAX*MAX], temp2[MAX*MAX];
    for(int i = 0; i < MAX*MAX; i++) {
        temp[i] = t1[i / MAX][i % MAX];
    }
    BottomUpMergeSort(temp, temp2, MAX*MAX);

    t2[0] = temp[0];
    for(int i = 1, j = 1; i < MAX*MAX; i++) {
        if(t2[j-1] < temp[i]) {
            t2[j] = temp[i]; j++;
        }
    }
}

int main() {
    SetT1andT2();
    PrinterT1();
    PrinterT2();
    cout << endl;
    Rewriter();
    PrinterT2();

    return 0;
}