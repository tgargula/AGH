#include <iostream>

using namespace std;

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}

int partition(int tab[], int p, int r) {
    int x = tab[r], i = p - 1;
    for( int j = p; j < r; j += 1) {
        if( tab[j] <= x ) {
            i += 1;
            swap(&tab[i], &tab[j]);
        }
    }
    swap(&tab[i+1], &tab[r]);
    return i+1;
}

void quickSort(int tab[], int p, int r) {
    if( p < r ) {
        int q = partition(tab, p, r);
        quickSort(tab, p, q-1);
        quickSort(tab, q+1, r);
    }
}

void printArray(int tab[]) {
    for (int i = 0; i < 15; i += 1) {
        cout << tab[i] << " ";
    }
    cout << '\n';
}

int main() {
    int tab[15] = {1, 2, 99, 22, 542, 54, 10, 3, 4, 4, 4, 2, 5, 1, 1};
    printArray(tab);
    quickSort(tab, 0, 14);
    printArray(tab);
    return 0;
}