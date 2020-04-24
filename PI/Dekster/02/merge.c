#include <stdio.h>
#include <stdlib.h>

void swap (int *t, int j) {
    int temp = t[j];
    t[j] = t[j-1];
    t[j-1] = temp;
}

void sort(int *t, int n) { 
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (t[j-1] > t[j]) swap(t,j);
        }
    }
}

int merge(int *t1, int *t2, int *t3, int m, int n) {
	int i1 = 0, i2 = 0, i3 = 0;
    int last = -1;
    
    while (i1 < m && i2 < n) {
        if (t1[i1] <= t2[i2]) {
            if (t1[i1] != last) {    
                if (t1[i1] == t2[i2]) i2++;
                last = t3[i3++] = t1[i1];
            }
            i1++;
        } else {
            if (t2[i2] != last) last = t3[i3++] = t2[i2];
            i2++;
        }
    }

    while (i1 < m) {
        if (t1[i1] != last) last = t3[i3++] = t1[i1];
        i1++;
    }

    while (i2 < n) {
        if (t2[i2] != last) last = t3[i3++] = t2[i2];
        i2++;
    }

    return i3;
}

void print(int *t, int n) {
	for (int i = 0; i < n; i++) printf("%d\n", t[i]);
}

int main() {

	int m, n;
	scanf("%d %d", &m, &n);

	int *t1 = (int*) malloc(m * sizeof (int));
    int *t2 = (int*) malloc(n * sizeof (int));
    int *t3 = (int*) malloc((n+m) * sizeof (int));

	for (int i = 0; i < m; i++) {
		scanf("%d", &t1[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &t2[i]);
	}

	sort(t1, m);
	sort(t2, n);

	int l = merge(t1, t2, t3, m, n);

	print(t3, l);

	free(t1);
    free(t2);
    free(t3);
}