/*
5.Poprzednie zadanie z tablicą wypełnioną liczbami całkowitymi
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
const int N=10, MAX=100;
int Result(int tab[N][N]){
int dwa[2];
double knMAX=0;
int idknMAX=0;
double kpMAX=0;                     // w nazwach zmiennych k to kolumna , w to wiersz, n ujemne p dodatnie
int idkpMAX=0;                      // zatem np. knMIN to najmniejsza ujemna suma el. kolumny w tablicy
double wnMIN=-N*MAX;                // id to indeksy oznaczające nr kolumny lub wiersza dla której zostało osiągniete
int idwnMIN=0;                      // dane minimum/maximum
double wpMIN=N*MAX;
int idwpMIN=0;
int temp=0;                         //temp to aktualna suma podczas liczenia sumy elementów
for(int i=0;i<N;i++){
        temp=0;
    for(int j=0;j<N;j++){
        temp+=tab[j][i];
        if(j==N-1){
        if(temp>0 && temp<wpMIN){
            wpMIN=temp;
            idwpMIN=i;}
        if(temp<0 && temp>wnMIN){
            wnMIN=temp;
            idwnMIN=i;}
        }
    }
}
for(int i=0;i<N;i++){
    temp=0;
    for(int j=0;j<N;j++){
        temp+=tab[i][j];
        if(j==N-1){
        if(temp>0 && temp>kpMAX){
            kpMAX=temp;
            idkpMAX=i;}
        if(temp<0 && temp<knMAX){
            knMAX=temp;
            idknMAX=i;}
        }
    }
}
if(wnMIN!=0 && wpMIN!=0){
    if(kpMAX/wpMIN >= knMAX/wnMIN){
        dwa[0]=idkpMAX;             //dwa to tablica zawierająca nasze szukane nr kolumny i wiersz
        dwa[1]=idwpMIN;}
    if(kpMAX/wpMIN < knMAX/wnMIN){
        dwa[0]=idknMAX;
        dwa[1]=idwnMIN;}
    }
if(wnMIN==0 && wpMIN!=0){
    dwa[0]=idkpMAX;
    dwa[1]=idwpMIN;}
if(wpMIN==0 && wnMIN!=0){
    dwa[0]=idknMAX;
    dwa[1]=idwnMIN;}
if(wnMIN==0 and wpMIN==0){
    dwa[0]=-1;
    dwa[1]=-1;}

cout<<dwa[0]<<" "<<dwa[1];
}

int main(){
int tab[N][N];
srand(time(NULL));
for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
    tab[j][i]=rand() % (2*MAX) - MAX;
}
cout << "i \\ j\t\t";
     for(int i = 0; i < N; i++) cout << i << "\t";
     cout << endl << "\t";
     for(int i = 0; i <= N; i++) cout << "--------";        //Tomkowa fancy tabelka, creditsy dla tego Pana !
     cout << endl;
     for(int i = 0; i < N; i++) {
         cout << i << "\t|\t";
         for(int j = 0; j < N; j++) {
             cout << tab[j][i] << "\t";
         }
         cout << endl;
     }
     cout << endl;

Result(tab);
return 0;

}