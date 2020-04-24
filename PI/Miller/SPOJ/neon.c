//https://pl.spoj.com/problems/KAMELNEO/
#include <stdio.h>
#include <stdlib.h>

int color(int arr[], int a, int k, int n){
	int *cycle = malloc(n * sizeof(int)); //indexing from 1
	cycle[0] = a;
	int j=1;
	while(arr[cycle[j-1]] != a){
		cycle[j] = arr[cycle[j-1]];
		j++;
	}
	if(j == 1)
		return a;
	return cycle[k%j];
}

int main(void){
	int n;
	scanf("%d", &n);
	int *arr = malloc((n+1) * sizeof(int));
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d", &x);
		arr[i] = x;
	}
	int t;
	scanf("%d", &t);
	while(t--){
		int a, k;
		scanf("%d%d", &a, &k);
		printf("%d\n", color(arr, a, k, n));
	}
	return 0;
}
