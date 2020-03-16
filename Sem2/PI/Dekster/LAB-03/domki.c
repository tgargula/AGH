#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int N;
    scanf("%d", &N);

    if (N < 2) { printf("0"); return 0; }

    int *tab = malloc (N * sizeof(int));
    long long sum2 = 0;
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &tab[i]);
        sum2 += tab[i];
    }

    if (N == 2) {
        if (tab[0] == 0) { printf("1"); return 0; }
        if (tab[1] == 0) { printf("0"); return 0; }
    }

    sum2 -= tab[0] + tab[1];
    long long sum1 = tab[0];
    int temp = tab[1];
    int index = 1;

    while (sum1 != sum2) {
        sum1 += temp;
        temp = tab[++index];
        sum2 -= temp;
    }

    printf("%d\n", index);

    free(tab);

    return 0;

}