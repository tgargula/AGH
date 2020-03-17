// a. Jaki jest typ i zakres losowanych liczb.

// b. Jak wpisac do programu wartość liczby pi.

// c. Jak zmienić zakres wylosowanych liczb do żądanego w zadaniu?

// d. Jak eksperymentalnie sprawdzić:
//    - ile różnych liczb dotarcza standardowy generator liczb pseudolosowych rand(),       - porównać każdą liczbę z aktualnym max, przy wykonywaniu 1 000 000 000 losowań
//    - czy generowane liczby się powtarzają, ew. kiedy zaczynają się powtarzać,            - … 
//    - jeżeli w eksperymencie będzie potrzebna pętla lub tablica, to:                      
//      * jakiego typu powinna być zmienna indeksowa tablicy, zmienna będąca "licznikiem iteracji",         - int, int
//      * jak sprawdzić, czy nie braknie pamięci dla tablicy, czy tablica powinna być lokowana na stosie, czy na stercie, jaki typ wybrać dla elementów tablicy, czy dla oszczędności pamięci można byłoby zapamiętywać wylosowanie każdej z liczb w jednym bicie odpowiadającym jej wartości?  

// e. Czy dla wyznaczenia jednego  punktu potrzebne są dwa losowania, czy z dwóch losowań można wyznaczyć dwa punkty, czy będę losowe, czy to ma znaczenie, kiedy? jaka symetria między tymi punktami?

// f. Jaką maksymalną dokładność obliczanej całki można otrzymać? 

// g. Czy zmiana warunku < na <= w warunku rozstrzygającym, czy wylosowany punkt zaliczać do całki, czy nie - ma wpływ na dokładność wyniku?

// h. Ile cyfr wyniku powinno pojawić się na ekranie? Jak to zrealizować używając funkcję printf?

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const int pi = 31415962, shots = 10000000;      // odp b)

double MonteCarlo() {
    int hits = 0;
    srand(time(0));
    for (int i = 0; i < shots; i += 1) {
        srand(rand());
        int x = rand() % pi, y = rand() % 10000000;     // odp c)
        // printf("x %d, y %d\n", x, y);
        if ( sin(x) <= (double) y/10000000 ) hits += 1;
    }
    // printf("hits %d\n", hits);
    double result = (double) hits/shots;
    result *= 3.1415962;
    return result;
}

int main() {
    printf("%lf\n", MonteCarlo());
    return 0;
}