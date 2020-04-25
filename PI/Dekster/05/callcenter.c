#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int sec;
    char *tel;
    struct Node *next;
} Node;

void add (Node *queue, int sec, char *tel) {

    Node *node = (Node *) malloc (sizeof(Node));
    node->sec = sec; node->tel = tel; node->next = NULL;

    while (queue->next != NULL) queue = queue->next;
    queue->next = node;

}

void pop (Node *queue, int sec) {

    Node *node = queue->next;
    queue->next = queue->next->next;

    printf("%s %d\n", node->tel, sec - node->sec);

    free(node->tel);
    free(node);

}

void freeMemory (Node *queue) {

    Node *curr = queue->next;
    Node *prev = queue;
    free(prev);

    while (curr != NULL) {
        Node *prev = curr;
        curr = curr->next;
        free(prev->tel);
        free(prev);
    }

}

void callCenter (int n) {

    Node *queue = (Node *) malloc(sizeof(Node));
    queue->sec = -1; queue->tel = "0"; queue->next = NULL;  // Sentinel node

    for (int i = 0; i < n; i++) {
        char type; int sec;
        scanf("\n\n%c%d", &type, &sec);

        if (type == 'a') {
            char *tel = malloc (16 * sizeof(char)); 
            scanf("%s", tel);
            add(queue, sec, tel);
        } else if (type == 'r') pop(queue, sec);
    }

    freeMemory(queue);

}


int main (void) {

    int n; scanf("%d", &n);

    callCenter(n);

    return 0;

}