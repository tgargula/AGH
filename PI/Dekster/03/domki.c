#include <stdio.h>
#include <stdlib.h>

int findIndex (int *tab, int N, long long sum) {
    
    if (N < 2) return 0;
    
    if (N == 2) {
    
        if (tab[0] == 0) return 1;
        if (tab[1] == 0) return 0;
    
    }

    long long sum1 = tab[0];
    int temp = tab[1];
    long long sum2 = sum - sum1 - temp;
    int index = 1;

    while (sum1 != sum2) {
        
        sum1 += temp;
        temp = tab[++index];
        sum2 -= temp;
    
    }

    return index;

}

int main (void) {

    int N;
    scanf("%d", &N);

    int *tab = malloc (N * sizeof(int));
    long long sum = 0;
    
    for (int i = 0; i < N; i++) {
    
        scanf("%d", &tab[i]);
    
        sum += tab[i];
    
    }

    int index = findIndex(tab, N, sum);

    printf("%d\n", index);

    free(tab);

    return 0;

}