#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 1000

typedef struct node {
    char* word;
    int counter;
    struct node* next;
} node;


node* insertWord(node* first, char* word) {
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

void processSingleWord(char* word, node** list) {
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

void processLine(char* line, node** list) {
   char *token;
   token = strtok(line, " /");
   while( token != NULL ) {
       processSingleWord(token, list);
       token = strtok(NULL, " /");
   }
}

node* processFile(node* first) {
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


    char* outputFileName = "./dictionary.txt";
    FILE *listTxt = fopen(outputFileName, "w");
    node* listIterator = first;
    
    while (listIterator != NULL) {
        char* integer = malloc(sizeof(char)*3), *text = "";
        snprintf(integer, 3, "%d", listIterator->counter);
        text = strcat(strcat(listIterator->word, "\n"), strcat(integer, "\n"));
        fprintf(listTxt, "%s", text);
        node* previous = listIterator; 
        listIterator = listIterator->next;
        free(previous);
    }
    free(listIterator);
    fclose(listTxt);

    return first;
}

void enddelchar(char* str, const char ch) {       // usuwanie ostatniego znaku - potrzebne ponieważ znak ostatni wczytany z tekstu to \n
  int len = strlen(str);
  char* ptr = str + (len-1);

  while (*ptr == ch)
    *ptr-- = '\0';
}

void checkWord(node* first) {
    char str[50];
    printf("Type the word you would like to check: ");
    scanf("%s", str);

    char* inputFileName = "./dictionary.txt";
    FILE * txtfile = fopen(inputFileName, "r");
    if (txtfile == NULL) {
        printf("Can not open txtfile %s\n", inputFileName); 
        return;
    }
    
    char str2[50];
    int flag = 0;
    while (fgets(str2, 50, txtfile) != NULL) {
        enddelchar(str2, '\n');
        if (strcmp(str, str2) == 0) {
            printf("Number of word '%s' occurences: %s\n", str, fgets(str2, 50, txtfile)); flag = 1; break;
        } 
    }
    if (flag == 0) {
        printf("Word does not found in list\n");
    }

    fclose(txtfile);
}

int main() {
    node* first = NULL;
    
    first = processFile(first);
    if(first == NULL) return 0;
    checkWord(first);
    
    return 0;
}