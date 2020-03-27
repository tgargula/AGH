// Program sprawdza, czy w łańcuchu znakowym jest prawidłowa kolejność nawiasów typu
// (). [] i {}.

// Założenia:
//     Nawiasy występują wśród dowolnych innych znaków ASCII.
//     Nawiasy mogą być zagnieżdżone, np. (...[..]..{..}..)..
//     Oba nawiasy jednej pary muszą być na tym samym "poziomie".

// Przykład nieprawidłowej kolejności:  ([)] 

// Wersje programu: Program czyta ciąg znaków z:
//     klawiatury i sygnalizuje błędną kolejność po wprowadzeniu znaku końca klawiszem
// ENTER,
//     z jednowymiarowej tablicy typu char, w której jest zapisany łańcuch znakowy,
//     z kolejnych wierszy tablicy dwuwymiarowej, w których są zapisane łańcuchy

// różnej długości.


// Assumptions for solution:
// 0 - () ; 1 - [] ; 2 - {}

#include <stdio.h>
const int N = 100;

void areBracketsCorrect(char chain[], int lastBracket, int *i, int *result, int level) {     // check if chain is correct
    if(*result == 0) return;
    while(chain[*i] != '\0') {          // if chain[*i] wasn't set is euqal '\0' - check only for set characters
        if(chain[*i] == '(') { *i += 1; areBracketsCorrect(chain, 0, i, result, level+1); }     // set new last bracket to (, go to the next recursion level
        else if(chain[*i] == '[') { *i += 1; areBracketsCorrect(chain, 1, i, result, level+1); }// set new last bracket to [, go to the next recursion level
        else if(chain[*i] == '{') { *i += 1; areBracketsCorrect(chain, 2, i, result, level+1); }// set new last bracket to {, go to the next recursion level
        else if(chain[*i] == ')' && lastBracket != 0) { *result = 0; return; } // protect [(])
        else if(chain[*i] == ']' && lastBracket != 1) { *result = 0; return; } // protect {[}]
        else if(chain[*i] == '}' && lastBracket != 2) { *result = 0; return; } // protect ({)}
        else if(chain[*i] == ')') { return; } // level down recursion
        else if(chain[*i] == ']') { return; } // level down recursion
        else if(chain[*i] == '}') { return; } // level down recursion
        *i += 1;
    }

    if(level != 0) {        // if recursion level is not 0 some brackets are not closed; protects ([]
        *result = 0; return;
    }
}

void chainVersion() {
    char chain[N]; scanf("%s", chain);
    int walkAroundArray = 0, *i = &walkAroundArray, res = 1, *result = &res; // res = 1 - it is assumed that chain is correct
    areBracketsCorrect(chain, 3, i, result, 0);         // 3 is last brace becouse must be something different than 0, 1, 2 which means braces
    if(res == 1) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return;
}

void multiChainVersin() {
    char multiChain[N][N];
    int walkAroundArray = 0, *i = &walkAroundArray, res, *result = &res; 

    for(int howMuch = 0; howMuch < N; howMuch += 1) {
        scanf("%s", multiChain[howMuch]);
        if(multiChain[howMuch][0] == '~') {multiChain[howMuch][0] = '\0'; break;}       // ~ means end of input next rows
    }   

    for(int howMuch = 0; multiChain[howMuch][0] != '\0'; howMuch += 1) {
        *result = 1;                // res = 1 - it is assumed that chain is correct
        *i = 0;                     // very important to change values of res to 1 and *i to 0
        areBracketsCorrect(multiChain[howMuch], 3, i, result, 0);
        if(res == 1) {
            printf("True\n");
        } else {
            printf("False\n");
        }
    }
}

int main() {
    chainVersion();
    // multiChainVersin();
    return 0;
}
