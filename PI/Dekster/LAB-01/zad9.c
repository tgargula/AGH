#include <stdio.h>

inline int max (int a, int b) { return a > b ? a : b; }

int sumOfGreatestSubstring(int tab[], int size) {
    int localMax, totalMax;
    localMax = totalMax = 0;
    for (int i = 0; i < size; i++) {
        localMax = max(tab[i], localMax + tab[i]);
        totalMax = max(totalMax, localMax);
    }
    return totalMax;
}

int main(void) {
    int tab1[6] = {1,2,-5,4,-3,2};
    int tab2[4] = {-1,-1,-3,-15};
    int tab3[7] = {1,2,3,4,-1,8,10};

    printf("%d\n", sumOfGreatestSubstring(tab1,6));
    printf("%d\n", sumOfGreatestSubstring(tab2,4));
    printf("%d\n", sumOfGreatestSubstring(tab3,7));

    return 0;
}