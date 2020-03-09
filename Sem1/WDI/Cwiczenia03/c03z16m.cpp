/*
16.Dana jest duża tablicaint t[MAX].  Proszę napisać funkcję, która zwraca informację czy w tablicy zachodzi następujący warunek: „wszystkie elementy, 
których indeks jest elementem ciągu Fibonacciego są liczbami złożonymi, a wśród pozostałych przynajmniej jedna jest liczbą pierwszą”
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

const int N=10;
int a=1;
int b=1;
bool prime=false;
int tab[N];

int main(){
    for(int i=0;i<N;i++){
        int licz=0;
        cin>>tab[i];
        if(i==b){
            for(int j=2;j<=sqrt(tab[i]);j++){
                if(tab[i]%j==0){
                    licz++;
                    break;
                }
            }
    if(licz==0) goto koniec;
    b+=a;
    a=b-a;
        }
    if(!(i==b) && prime==false){
        for(int j=2;j<=sqrt(tab[i]);j++){
                if(tab[i]%j==0) goto skok;}
    prime=true;
    skok:
    string ponic;
    }
    }
    if(!prime) cout<<"NIE";
    else cout<<"TAK";
    return 0;
    koniec:
    cout<<"NIE";
}