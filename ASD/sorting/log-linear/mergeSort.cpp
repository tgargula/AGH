#include <iostream>

using namespace std;

const int N = 11;

void merge(int tab[], int start, int middlePoint, int finish) {
    int i, j, k;
    int t1Length = middlePoint - start + 1, t2Length = finish - start;
    int tab1[t1Length], tab2[t2Length];     // create arrays to storge temp data

    for(i = 0; i < t1Length; i+=1) tab1[i] = tab[start+i];      // copy data to arrays
    for(j = 0; j < t2Length; j+=1) tab2[j] = tab[middlePoint+1+j];

    i = j = 0; k = start;

    while(i < t1Length and j < t2Length) {       // merge 
        if(tab1[i] <= tab2[j]) {
            tab[k] = tab1[i]; i+=1;
        } else {
            tab[k] = tab2[j]; j+=1;
        }
        k+=1;
    }

    while(i < t1Length) {
        tab[k] = tab1[i]; i+=1; k+=1;
    }
    while(j < t2Length) {
        tab[k] = tab2[j]; j+=1; k+=1;
    }
}

void mergeSort(int tab[], int start, int finish) {
    if(start < finish) {                            // make two halves
        int middlePoint = start + (finish - start) / 2;
        mergeSort(tab, start, middlePoint);
        mergeSort(tab, middlePoint+1, finish);

        merge(tab, start, (start+finish)/2, finish);
    }
}

void printArray(int tab[], int tabSize) {
    for(int i = 0; i < tabSize; i+=1) cout << tab[i] << " ";
    cout << '\n';
}

int main() {
    int tab[N] = {3,5,2,3,10,8,4,7,6,1,9};
    mergeSort(tab, 0, N-1);
    printArray(tab, N);
    return 0;
}