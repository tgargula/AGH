//https://pl.spoj.com/problems/JSUMDUZE/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(char *a, char *b){
	int size_a = (int)(strlen(a));
	int size_b = (int)(strlen(b));
	int min_size, max_size;
	if(size_a >= size_b){
		max_size = size_a;
		min_size = size_b;
	}else{
		max_size = size_b;
		min_size = size_a;
	}
	int *max = malloc((max_size+1) * sizeof(int)); //+1 for optional remainder, will add shorter number to longer modifying the longer one
        max[0] = 0;
	int *min = malloc(min_size * sizeof(int));
        if(size_a >= size_b){
		for(int i=0; i<max_size; i++)
        		max[i+1] = (int)(a[i]) -48; //char to int
        	for(int i=0; i<min_size; i++)
                	min[i] = (int)(b[i]) -48;
	}else{
		for(int i=0; i<max_size; i++)
                	max[i+1] = (int)(b[i]) -48; //char to int
        	for(int i=0; i<min_size; i++)
                	min[i] = (int)(a[i]) -48;
	}
	for(int i=0; i<min_size; i++){ //add shorter to longer
		max[max_size -i] += min[min_size -i -1];
		max[max_size -i -1] += max[max_size -i]/10;
		max[max_size -i] %= 10;
	}
	if(max[0] != 0)
		printf("%d", max[0]);
	for(int i=1; i<max_size+1; i++)
		printf("%d", max[i]);
	printf("\n");
}

int main(void){
	int t;
	scanf("%d", &t);
	char x[1002], y[1002];
	while(t--){
		scanf("%s%s", x, y);
		add(x, y);
	}
	return 0;
}
