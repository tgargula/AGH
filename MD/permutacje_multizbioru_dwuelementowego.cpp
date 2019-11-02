// Program wypisuje wszystkie permutacje wybranego multizbioru dwuelementowego

#include <iostream>

using namespace std;

const int n = 9;
bool t[n] = {0,0,0,0,1,1,1,1,1};
int j, k, l, i, c=0;

int main() {
    for(int i = 0; i<n; i++) cout << t[i];

    do {
        for(int i = 0; i < n; i++) cout << t[i];
        cout << endl; c++;
        i = n - 2;
        while(i >= 0 && t[i]>=t[i+1]) i--;
        if(i >= 0) {
            j = n-1;
            while(t[j] <= t[i]) j--;
            swap(t[i], t[j]);
            k = i + 1;
            l = n - 1;
            while(l > k) {
                swap(t[l],t[k]);
                k++;
                l--;
            }
        }
    }   while(i >= 0);

    cout << c << endl;

    return 0;
}