#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

const int MAX=4;

void Spir(int tab[MAX][MAX]){
    int t=MAX/2 , k=MAX/2;
    tab[k][t]=1;
    int temp=1;
    int ks,ts;
    bool flag;
    for(int i=1;temp<=(MAX)*(MAX) && flag;i++){
        ks=i;
        ts=i;
        do{
        if(temp==MAX*MAX){
        flag=false;
        break; }
        temp++;
        ts--;
        t=t+pow(-1,i);
        tab[k][t]=temp;
        }
        while(ts>0);

        do{
        if(temp==MAX*MAX){
        flag=false;
        break; }
        temp++;
        ks--;
        k=k+pow(-1,i);
        tab[k][t]=temp;}
        while(ks>0);
    }
}
int main(){
    int tab[MAX][MAX];
    Spir(tab);
    for(int i=0;i<=MAX-1;i++){
        for(int j=0;j<=MAX-1;j++){
        cout<<tab[j][i]<< "\t";}
        cout<<endl;
    }
}

