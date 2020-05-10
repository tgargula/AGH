#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Contact {
    char name[31];
    char number[31];
    struct Contact *next;
} Contact;

bool equals(char s1[31], char s2[31]) {
    int i = 0;
    while (s1[i] != '\0') {
        if (s1[i] != s2[i]) return false;
        i++;
    }
    if (s2[i] != '\0') return false;
    return true;
}

int hash(char *name, int n) {
    int i = 0;
    int h = 0;
    while (name[i] != '\0') {
        h += name[i++];
        h %= n;
    }
    return h;
}

Contact *search(Contact **list, char *name, int n) {
    int h = hash(name, n);
    Contact *contact = list[h];
    while (contact->next != NULL && !equals(contact->next->name, name)) contact = contact->next;
    return contact;
}

void insert(Contact **list, char name[31], char number[31], int n) {
    int h = hash(name, n);
    Contact *new = malloc(sizeof(Contact));
    strcpy(new->name, name);
    strcpy(new->number, number);
    new->next = list[h]->next;
    list[h]->next = new;
}

void purge(Contact **list, char *name, int n) {
    Contact *contact = search(list, name, n);
    Contact *toRemove = contact->next;
    contact->next = contact->next->next;
    free(toRemove);
}

void get(Contact **list, char *name, int n) {
    Contact *contact = search(list, name, n);
    if (contact->next == NULL) printf("\n");
    else printf("%s\n", contact->next->number);
}

int main(void) {
    int Z;
    scanf("%d", &Z);
    while (Z--) {
        int n;
        int k;
        scanf("%d%d", &n, &k);
        Contact **list = malloc(n*sizeof(Contact*));
        for (int i = 0; i < n; i++) {
            list[i] = malloc(sizeof(Contact));
            list[i]->next = NULL;
        }
        for (int i = 0; i < k; i++) {
            char type;
            char name[31];
            char number[31];
            scanf("\n%c", &type);
            scanf("%30s", name);
            switch (type) {
                case 'a':
                    scanf("%30s", number);
                    insert(list, name, number, n);
                    break;
                case 'r':
                    purge(list, name, n);
                    break;
                case 'g':
                    get(list, name, n);
                    break;
                default:
                    printf("Invalid type");
                    break;
            }
            // showLists(list, n);
        }
        for (int i = 0; i < n; i++) {
            while (list[i] != NULL) {
                Contact* toRemove = list[i];
                list[i] = list[i]->next;
                free(toRemove);
            }
        }
        free(list);
    }
    return 0;
}