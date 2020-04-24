// test struktury nawiasów - wersja czytania z klawiatury

#include <stdio.h>

int szukaj_nawiasu(char nawias_zamyk, int poziom) {
	char c;
	int odp;
	do {
//		c=fgetc(stdin);
        c = getchar();
		if(c == nawias_zamyk) {
			if(c=='\n') return poziom;
			return 0;                                    // OK - poprawne zamkniecie nawiasu
	    }
		odp = 0;
		switch(c) {
			case '\n': return -2;                        // Blad - nieoczekiwany koniec
			case ')': case ']': case '}':   return -1;   // Blad - zle zamkniecie
			case '(':  odp = szukaj_nawiasu(')', poziom+1);  break;  // s¹ osoby, które zauwa¿y³y, ¿e kody naiasu zamekaj¹cego ró¿ni¹ siê od kody nawiasu otwieraj¹cego o 1 lub 2 - mo¿na to wykorzystaæ
			case '[':  odp = szukaj_nawiasu(']', poziom+1);  break; 
			case '{':  odp = szukaj_nawiasu('}', poziom+1);  break; 
		}                                                // inny znak (default) nie nie zmiena 
	}	while(odp==0);		
	return odp;
}
int main(void) {
	int odp, poziom = 0;
	printf("Wpisuj kolejne wyrazenia, az do niepoprawnego: \n");
    do {
		odp = szukaj_nawiasu('\n',poziom);    // znak przejœcia do nowej linii jest traktowany jak znak nawisu zamykaj¹cego
	    if(odp==0) printf("Poprawny. Wpisz nastepny\n");
	} while(odp==0);
	printf("BLAD!!! - koniec\n");
	return 0;
}
