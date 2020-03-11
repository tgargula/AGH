//https://pl.spoj.com/problems/ETI06F3/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insertion_sort(int arr[], int n){ //lame implementation im too sleepy sori
	int k;
    	for(int i=0; i<n; i++){
		k=i-1;
		while(k>=0 && arr[i] < arr[k]){
			k--;
		}
		int tmp = arr[i];
		for(int j=i; j>k+1; j--){ //shift
			arr[j] = arr[j-1];
		}
		arr[k+1] = tmp; //insert
    }
}

void divide(int n, int arr[100][100]){
	bool *is_in = malloc(n * sizeof(bool));
      	for(int i=1; i<n; i++)
		is_in[i] = false;
	int team1 = 1;
	is_in[0] = true;
	for(int i=1; i<n; i++){ //check who knows first one
		if(arr[0][i] == 1){
			team1++;
			is_in[i] = true;
		}
	}
	int team2, team3;
	int counter = 1;
	for(int i=1; i<n; i++){
		if(!is_in[i]){
			if(counter > 2){
				printf("NIE\n");
				return;
			}
			int tmp = 1;
			for(int j=i+1; j<n; j++){
				if(arr[i][j] == 1 && is_in[j]){
					printf("NIE\n");
					return;
				}
				if(arr[i][j] == 1){
					is_in[j] = true;
					tmp++;
				}
			}
			if(counter == 1)
				team2 = tmp;
			if(counter == 2)
				team3 = tmp;
			counter++;
		}
	}
	if(counter < 2 || team2 == 0 || team3 == 0){
		printf("NIE\n");
		return;
	}
	int results[3];
	results[0] = team1;
	results[1] = team2;
	results[2] = team3;
	insertion_sort(results, 3);
	printf("TAK ");
	for(int i=0; i<3; i++)
		printf("%d ", results[i]);
	printf("\n");
}

int main(void){
	int n;
	scanf("%d", &n);
	int arr[100][100];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int x;
			scanf("%d", &x);
			arr[i][j] = x;
		}
	}
	divide(n, arr);
	return 0;
}

