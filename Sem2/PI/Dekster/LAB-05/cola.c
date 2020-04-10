#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int key;
    int ctr;
} Node;

int main() {

    int n;
    scanf("%d", &n);
    int *T = malloc (n * sizeof(int));

    Node *output = malloc(n * sizeof(Node));

    int size = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &T[i]);

        bool b = false;
        for (int j = 0; j < size; j++) if (output[j].key == T[i]) { output[j].ctr++; b = true; break; }

        if (!b) {
            output[size].key = T[i];
            output[size].ctr = 1;
            size++;
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d %d\n", output[i].key, output[i].ctr);
    }

    free(output);

    return 0;

}