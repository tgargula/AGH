//https://pl.spoj.com/problems/MWPZ06Z/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool can_we(int n, char c[]){
	int x; //last three digits of c
	int size = strlen(c);
	x = c[size-1] - 48;
	if(size > 1){
		x += (c[size-2] - 48)*10;
	}
	if(size > 2){
		x += (c[size-3] -48)*100;
	}
	if(x%n == 0)
		return true;
	return false;
}

void print_result(int a, char b[]){
	if(can_we(a, b))
		printf("TAK\n");
	else
		printf("NIE\n");
}

int main(){
	int d;
	scanf("%d", &d);
	int x;
	char y[10000];
	while(d--){
		scanf("%d%s", &x, y);
		print_result(x, y);
	}
	return 0;
}
