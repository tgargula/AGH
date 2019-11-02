/*
15.Napisać program wyznaczający na drodze eksperymentu prawdopodobieństwo tego, 
że w grupie N przypadkowo spotkanych osób, co najmniej dwie urodziły się tego samego dnia roku. 
Wyznaczyć wartości prawdopodobieństwa dla N z zakresu 20-40.
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

//n to liczba dni w roku
//k to liczba osób

using namespace std;

double prob(double n, double k){
double ilo=1;
for(double i=0;i<k;i++){
ilo*=(1-i/n);
}
return 1-ilo;
}

int main(){
double n,k;
cin>>n;
cin>>k;
cout<<prob(n,k);
}