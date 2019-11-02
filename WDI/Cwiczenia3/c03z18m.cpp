/*
18.Funkcja wyznacza różnicę pomiędzy wartością maksymalną a minimalną.Ile minimalnie porównań trzeba wykonać?
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;

const int N=10;

int main(){
    int tab[N];
    int temp=0;
    int MAX=0;
    int MIN=2147483647;
    srand(time(NULL));

    for(int i=0;i<N;i++){
        srand(rand());
        tab[i] = rand() / 1234567;
        temp=tab[i];
        if(temp<MIN) MIN=temp;
        if(temp>MAX) MAX=temp;
    }

    for(int i=0;i<N;i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
    cout<<MAX-MIN<<endl;
    cout<<"2N Panie Garku";
}