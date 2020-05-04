#include <stdio.h>
#include <string.h>

#define MAXCHAR 1500        // zakładam, że w jednej linijce nie będzie więcej znaków niż 1500


void usunKomentarzeWielolinijkowe(char* linijka, int* czyWewnatrzKomentarza);
void usunKomentarzeJednolinijkowe(char* linijka, int* czyWewnatrzKomentarza);

int main(void) {
    char *nazwaWejscia = "./calkaSimpsona2.c";
    char linijka[MAXCHAR];
    int czyWewnatrzKomentarza = 0;          // True Flase - zmienna pomocnicza wykorzystywana przy określaniu czy dalej jesteśmy wewnątrz komentarza czy już nie

    FILE *plikWejscie = fopen(nazwaWejscia, "r");
    FILE *plikWyjscie = fopen("calkaSimpsonaBezKomentarzy.c", "w");
    
    if (plikWejscie == NULL) {               // sprawdzenie czy zadany plik istnieje
        printf("Could not open file %s", nazwaWejscia);
        return 1;
    }

    while (fgets(linijka, MAXCHAR, plikWejscie) != NULL) {      // wczytywanie pliku linijka po linijce
        usunKomentarzeJednolinijkowe(linijka, &czyWewnatrzKomentarza);
        usunKomentarzeWielolinijkowe(linijka, &czyWewnatrzKomentarza);

        fputs(linijka, plikWyjscie);        // dopisywanie do pliku
    }

    fclose(plikWejscie);
    fclose(plikWyjscie);        // bezpieczne wyjście z edycji/ czytania plików
    return 0;
}

void usunKomentarzeJednolinijkowe(char* linijka, int* czyWewnatrzKomentarza) {      // funkcja usuwająca komentarze jednolinijkowe 
    char* start = strstr(linijka, "//");

    if(start != NULL) {
        *start = '\n';
        *(start + 1) = '\0';
        *czyWewnatrzKomentarza = 0;
    } else return;
}

void usunKomentarzeWielolinijkowe(char* linijka, int* czyWewnatrzKomentarza) {      // funkcja rekurencyjna usuwająca komentarze wielolinijkowe

    if(*czyWewnatrzKomentarza == 1) {
        char* koniec = strstr(linijka, "*/");      // znajduje podciąg  w ciągu - zwraca wskaźnik do 1. char który, zaczyna ten podciąg czyli do '*'

        if(koniec != NULL) {
            koniec = koniec + 2;
            *czyWewnatrzKomentarza = 0;
            usunKomentarzeWielolinijkowe(koniec, czyWewnatrzKomentarza);
            *linijka = '\0';
            strcat(linijka, koniec);
            return;
        }

        *linijka = '\0';
        return;
    }

    char* start = strstr(linijka, "/*");
    if(start == NULL) {
        return;
    }

    char* koniec = strstr(start, "*/");
    *start = '\0';
    if(koniec == NULL) {
        strcat(linijka, "\n");
        *czyWewnatrzKomentarza = 1;
        return;
    }
    koniec = koniec + 2;                  // nie bierz konca komentarza "*/" do kodu

    usunKomentarzeWielolinijkowe(koniec, czyWewnatrzKomentarza);
    strcat(linijka, koniec);

}