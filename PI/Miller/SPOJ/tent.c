//https://pl.spoj.com/problems/ETI07F1/
#include <stdio.h>
#include <stdlib.h>

int maximum(int x, int y){
	if(x >= y)
		return x;
	return y;
}

int sew_rec(int n, int a, int b, int *arr1, int *arr2, int counter, int idx){
	if(idx == n || (arr1[idx] == 0 && arr2[idx] == 0))
		return counter;
	if(a - arr1[idx] >= 0 && b - arr2[idx] >= 0)
       		return maximum(sew_rec(n, a - arr1[idx], b - arr2[idx], arr1, arr2, counter+1, idx+1), sew_rec(n, a, b, arr1, arr2, counter, idx+1));
	else
		return sew_rec(n, a, b, arr1, arr2, counter, idx+1);
}

void print_answer(int n, int a, int b, int *arr1, int *arr2){
	int answer = sew_rec(n, a, b, arr1, arr2, 0, 0);
	printf("%d\n", answer);
}

int main(void){
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	int *arr1 = malloc(n * sizeof(int));
	int *arr2 = malloc(n * sizeof(int));
	for(int i=0; i<n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		arr1[i] = x;
		arr2[i] = y;
	}
	print_answer(n, a, b, arr1, arr2);
	return 0;
}	
