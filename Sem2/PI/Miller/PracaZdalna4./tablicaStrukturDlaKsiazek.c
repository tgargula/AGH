#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char title[50];
    int yearOfPublication;
    double price;
} book;

book inputBookData() {
    book book1;
    scanf("%s %s %d %lf", book1.name, book1.title, &(book1.yearOfPublication), &(book1.price));
    return book1;
}

void inputBookDataInFunction(book books[], int numberOfBooks) {
    for(int i = 0; i < numberOfBooks; i += 1) {
        books[i] = inputBookData();
    }
}

void printBookInfo(book book1) {
    printf("Autor: %s\nTytul: %s\nRok wydania: %d\nCena: %.2lf PLN\n", book1.name, book1.title, book1.yearOfPublication, book1.price);
}

void printAllBooks(book books[], int numberOfBooks) {
    for(int i = 0; i < numberOfBooks; i += 1) {
        printf("Ksiazka #%d\n", i+1);
        printBookInfo(books[i]);   
    }
}

int main() {
    int numberOfBooks;
    scanf("%d", &numberOfBooks);
    book books[numberOfBooks];
    inputBookDataInFunction(books, numberOfBooks);                                  //wersja B
    printAllBooks(books, numberOfBooks);
    // for(int i = 0; i < numberOfBooks; i += 1) books[i] = inputBookData();        //wersja A
    // printAllBooks(books, numberOfBooks);
    return 0;
}