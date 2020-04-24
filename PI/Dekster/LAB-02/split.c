#include <stdio.h>
#include <stdlib.h>

void swap (int *t, int j) {
    int temp = t[j];
    t[j] = t[j-1];
    t[j-1] = temp;
}

void sort (int *t, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (t[j-1] > t[j]) swap(t,j);
        }
    }
}

int split (int *t1, int *t2, int *t3, int n) {
    int i2 = 0, i3 = 0;
    for (int i = 0; i < n; i++) {
        if (t1[i] % 2 == 0) {
            t2[i2++] = t1[i];
        } else {
            t3[i3++] = t1[i];
        }
    }

    return i2;
}

void print (int *t, int n) {
	for (int i = 0; i < n; i++) printf("%d\n", t[i]);
}

int main() {

	int n;
	scanf("%d", &n);

    int *t1 = (int*) malloc(n * sizeof (int));
    int *t2 = (int*) malloc(n * sizeof (int));
    int *t3 = (int*) malloc(n * sizeof (int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &t1[i]);
	}

	int e = split(t1, t2, t3, n);
	int o = n - e;

	sort(t2, e);
	sort(t3, o);

	printf("%d %d\n", e, o);
	print(t2, e);
	print(t3, o);

	free(t1);
    free(t2);
    free(t3);
}