/*
12.Napisać funkcję, która dla tablicy int t[MAX] wypełnionej liczbami naturalnym wyznacza długość najdłuższego, spójnego podciągu geometrycznego.
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

const int MAX=10;
int main() {
int tab[MAX];
for(int i=0;i<MAX;i++)
    cin>>tab[i];
double r=0;
int temp=2;
int MS=2;
if(MAX==1) goto koniec;
if(MAX==2){
cout<<"2";
return 0;
}
else
for(int i=0;i<MAX-2;i++){
    r=tab[i+1]/tab[i];
    if(tab[i+2]/r==tab[i+1])
        temp++;
    if(tab[i+2]/r!=tab[i+1])
        temp=0;
    if(temp>MS)
        MS=temp;
}
cout<<MS;
return 0;
koniec:
cout<<"0";
}