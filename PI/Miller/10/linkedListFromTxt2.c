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

int isLetter(char ch) {
    int code = (int) ch;
    if ((97 <= code && code <= 122) || (65 <= code && code <= 90)) return 1;
    return 0;
}

int isValidCharacter(char character) {
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

Node* processFile(Node* first) {
    char inputFileName[] = "./tekst.txt";
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


    char outputFileName[] = "./dictionary.txt";
    FILE *listTxt = fopen(outputFileName, "w");
    Node* listIterator = first;
    
    while (listIterator != NULL) {
        char* integer = malloc(sizeof(char)*3), *text = "";
        snprintf(integer, 3, "%d", listIterator->counter);
        text = strcat(strcat(listIterator->word, "\n"), strcat(integer, "\n"));
        fprintf(listTxt, "%s", text);
        Node* previous = listIterator; 
        listIterator = listIterator->next;
        free(previous);
        free(integer);
    }
    free(listIterator);
    fclose(listTxt);

    return first;
}

void enddelchar(char str[], const char ch) {       // usuwanie ostatniego znaku - potrzebne ponieważ znak ostatni wczytany z tekstu to \n
    int len = strlen(str);
    str[len - 1] = '\0';
}

void checkWord(Node* first) {
    char str[MAXWORDCHAR];
    printf("Type the word you would like to check: ");
    scanf("%s", str);

    char inputFileName[] = "./dictionary.txt";
    FILE * txtfile = fopen(inputFileName, "r");
    if (txtfile == NULL) {
        printf("Can not open txtfile %s\n", inputFileName); 
        return;
    }
    
    char str2[MAXWORDCHAR];
    int flag = 0;
    while (fgets(str2, MAXWORDCHAR, txtfile) != NULL) {
        enddelchar(str2, '\n');
        if (strcmp(str, str2) == 0) {
            printf("Number of word '%s' occurences: %s\n", str, fgets(str2, MAXWORDCHAR, txtfile)); flag = 1; break;
        } 
    }
    if (flag == 0) {
        printf("Word does not found in list\n");
    }

    fclose(txtfile);
}

int main(void) {
    Node* first = NULL;
    
    first = processFile(first);
    if(first == NULL) return 0;
    checkWord(first);
    
    return 0;
}