//https://pl.spoj.com/problems/CANTOR/
#include <stdio.h>

void draw_triangle(int n){
	int first_col[2001];
	int size = 1;
	int last = 1;
	first_col[0] = 1;
	while(last <= n){
		last += size;
		size++;
		first_col[size-1] = last;
	}
	

	int to_print;
	int to_add;
	int j;
	for(int i=1; i<size; i++){
		to_print = first_col[size-i-1];
		to_add = size-i;
		for(j=0; j<i-1; j++){
			printf("%d ", to_print);
			to_add++;
			to_print += to_add;
		}
		if(to_print <= n)
			printf("%d", to_print);
		printf("\n");
	}
}

int main(void){
	int n;
	scanf("%d", &n);
	draw_triangle(n);
	return 0;
}
