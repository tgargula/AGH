#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 1000

typedef struct node {
    char* word;
    int counter;
    struct node* next;
} node;


node* insertWord(node* first, char* word) {     // wstawianie do listy w odpowiednim miejscu
    if(first == NULL) {
        first = (node*) malloc(sizeof(node));
        first->word = word;
        first->counter = 1;
        first->next = NULL;
        return first;
    }
    
    node* listIterator = first;
    node* previous = NULL;

    while(listIterator != NULL && strcmp(word, listIterator->word) > 0) {
        previous = listIterator; listIterator = listIterator->next;
    }
    
    if(listIterator != NULL && strcmp(word, listIterator->word) == 0) {
        listIterator->counter += 1; return first;
    }

    node* newNode = (node*) malloc(sizeof(node));
    newNode->word = word;
    newNode->counter = 1;
    newNode->next = listIterator;
    
    if(previous == NULL) return newNode;
    previous->next = newNode;
    return first;
}

int isLetter(char ch) {         // określenie czy to litera
    int code = (int) ch;
    if ((97 <= code && code <= 122) || (65 <= code && code <= 90)) return 1;
    return 0;
}

int isValidCharacter(char character) {      // określnie czy to znak zgodny z wymogami polecenia
    int code = (int) character;
    if ((isLetter(character)) || (code >= 48 && code <= 57) || (code == '\'' || code == '-')) return 1;
    else return 0;
}

void processSingleWord(char* word, node** list) {       // przetwarzanie pojedynczego wyrazu
    int i2 = 0;
    
    for (int i = 0; word[i] != '\0'; i++) { 
        if (65 <= word[i] && word[i] <= 90) {
            word[i] += 32;
        }
        if (isValidCharacter(word[i])) {
            word[i2++] = word[i];
        }
    }
    
    word[i2] = '\0';
    if (isLetter(word[0]) == 0) return; 
    char *s = (char*)malloc(strlen(word) * sizeof(char));
    strcpy(s, word);
    *list = insertWord(*list, s);
}

void processLine(char* line, node** list) {             // przetwarzanie pojedynczej linii 
   char *token;
   token = strtok(line, " /");
   while( token != NULL ) {
       processSingleWord(token, list);
       token = strtok(NULL, " /");
   }
}

node* processFile(node* first) {                        // przetwarzanie pliku
    char* inputFileName = "./tekst.txt";
    FILE * txtfile = fopen(inputFileName, "r");
    char str[MAXCHAR];
    if (txtfile == NULL) {
        printf("Can not open txtfile %s\n", inputFileName); 
        return first;
    }
    
    while (fgets(str, MAXCHAR, txtfile) != NULL) {
        processLine(str, &first);
    }

    fclose(txtfile);
    return first;
}

void printList(node* first) {                           // wypisanie listy
    int nodde = 0;
    while(first != NULL) {
        printf("Node order number: %d\t, Number of word occurences: %d\t, Word: %s\n\n", nodde, first->counter, first->word);
        first = first->next;
        nodde++;
    }
}

void checkWord(node* first) {                           // sprawdzenie czy słowo się pojawiło
    if(first == NULL) {
        printf("Nothing to print - list is empty\n"); return;
    }

    char str[MAXCHAR];
    printf("Type the word you would like to check: ");
    scanf("%s", str);

    int listIterator = 0;
    while(strcmp(first->word, str) != 0) {
        first = first->next;
        listIterator++;
        if(first == NULL) {
            printf("Word does not found in list\n"); return;
        }
    }

    printf("Node order number: %d\n", listIterator);
    printf("Number of word occurences: %d\n", first->counter);
}

int main() {
    node* first = NULL;
    
    first = processFile(first);
    if(first == NULL) return 0;
    printList(first);
    checkWord(first);

    while (first != NULL) {
        node* previous = first;
        first = first->next;
        free(previous);
    }
    
    return 0;
}