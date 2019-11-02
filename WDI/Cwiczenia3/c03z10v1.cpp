#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

const int MAX = 10;
int main(){
int tab[MAX];
for(int i=0;i<MAX;i++)
    cin>>tab[i];
int temp=1;
int Ms=0;
for(int i=1;i<=MAX-1;i++){
   if(tab[i-1]<tab[i])
    temp++;
   if(tab[i-1]>=tab[i])
    temp=0;
   if(temp>Ms)
    Ms=temp;
}
cout<<Ms;
}
