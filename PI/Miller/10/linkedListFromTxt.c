#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 1001
#define MAXWORDCHAR 101

typedef struct Node {
    char word[MAXWORDCHAR];
    int counter;
    struct Node* next;
} Node;


Node* insertWord(Node* first, char word[]) {     // wstawianie do listy w odpowiednim miejscu
    if(first == NULL) {
        first = (Node*) malloc(sizeof(Node));
        memset(first->word, '\0', sizeof(first->word));
        strcpy(first->word, word);
        first->counter = 1;
        first->next = NULL;
        return first;
    }
    
    Node* listIterator = first;
    Node* previous = NULL;

    while(listIterator != NULL && strcmp(word, listIterator->word) > 0) {
        previous = listIterator; 
        listIterator = listIterator->next;
    }
    
    if(listIterator != NULL && strcmp(word, listIterator->word) == 0) {
        listIterator->counter += 1; 
        return first;
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    memset(newNode->word, '\0', sizeof(newNode->word));
    strcpy(newNode->word, word);
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

void processSingleWord(char word[], Node** list) {       // przetwarzanie pojedynczego wyrazu
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
    char s[MAXWORDCHAR]; // = (char*)malloc(strlen(word) * sizeof(char));
    strcpy(s, word);
    *list = insertWord(*list, s);
}

void processLine(char line[], Node** list) {             // przetwarzanie pojedynczej linii 
   char* token = strtok(line, " /");
   while( token != NULL ) {
       processSingleWord(token, list);
       token = strtok(NULL, " /");
   }
   free(token);
}

Node* processFile(Node* first) {                        // przetwarzanie pliku
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

void printList(Node* first) {                           // wypisanie listy
    int nodde = 0;
    while(first != NULL) {
        printf("Node order number: %d\t, Number of word occurences: %d\t, Word: %s\n\n", nodde, first->counter, first->word);
        first = first->next;
        nodde++;
    }
}

void checkWord(Node* first) {                           // sprawdzenie czy słowo się pojawiło
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

int main(void) {
    Node* first = NULL;
    
    first = processFile(first);
    if(first == NULL) return 0;
    printList(first);
    checkWord(first);

    while (first != NULL) {
        Node* previous = first;
        first = first->next;
        free(previous);
    }
    
    return 0;
}