#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MLEN 31

enum state { NIL, VISITED, DELETED };

typedef struct Contact {
    char name[MLEN];
    char number[MLEN];
    enum state s;
} Contact;

bool equals(char s1[MLEN], char s2[MLEN]) {
    int i = 0;
    while (s1[i] != '\0') {
        if (s1[i] != s2[i]) return false;
        i++;
    }
    if (s2[i] != '\0') return false;
    return true;
}

int bhash(char *name, int n) {
    int i = 0;
    int h = 0;
    while (name[i] != '\0') {
        h += name[i++];
        h %= n;
    }
    return h;
}

inline int hash(int h, int i, int n) {
    return (h + i*i) % n;
}

void insert(Contact *T, char name[MLEN], char number[MLEN], int n) {
    int i = 0;
    int h = bhash(name, n);
    while (i < n) {
        int j = hash(h, i, n);
        if (! (T[j].s == VISITED)) {
            strcpy(T[j].name, name);
            strcpy(T[j].number, number);
            T[j].s = VISITED;
            return;
        }
        i++;
    }
}

void purge(Contact *T, char name[MLEN], int n) {
    int i = 0;
    int h = bhash(name, n);
    while (i < n) {
        int j = hash(h, i, n);
        if (T[j].s == NIL) return;
        if (T[j].s == VISITED && equals(T[j].name, name)) {
            T[j].s = DELETED;
            return;
        }
        i++;
    }
}

void get(Contact *T, char name[MLEN], int n) {
    int i = 0;
    int h = bhash(name, n);
    while (i < n) {
        int j = hash(h, i, n);
        if (T[j].s == VISITED && equals(T[j].name, name)) {
            printf("%s\n", T[j].number);
            return;
        }
        if (T[j].s == NIL) {
            printf("\n");
            return;
        }
        i++;
    }
    printf("\n");
}

int main(void) {
    int Z;
    scanf("%d", &Z);
    while (Z--) {
        int n;
        int k;
        scanf("%d%d", &n, &k);
        Contact *T = malloc(n*sizeof(Contact));
        for (int i = 0; i < n; i++) {
            strcpy(T[i].name, ""); 
            strcpy(T[i].number, "");
            T[i].s = NIL;
        }
        for (int i = 0; i < k; i++) {
            char type;
            char name[MLEN];
            char number[MLEN];
            scanf("\n%c", &type);
            scanf("%30s", name);
            switch (type) {
                case 'a':
                    scanf("%30s", number);
                    insert(T, name, number, n);
                    break;
                case 'r':
                    purge(T, name, n);
                    break;
                case 'g':
                    get(T, name, n);
                    break;
                default:
                    printf("Invalid type");
                    break;
            }
        }
        free(T);
    }

    return 0;
}