// grubo rozstrzelone wszystko ale za chiny nie wiem co w tym kwestionariuszu należało zrobić :p

#include <stdio.h>
int main(void) {
	long int a=25, tab[16]={100.110,120,130,140,150,160,170}, b=500;
	long int *p=tab, *q=&b;
	int i=333;
	printf("sizeof(a) = %d, sizeof(p) = %d\n",sizeof(a),sizeof(p));
	printf("tab = %p\n",tab); 

	i = ++p - tab;

	// printf("%d\n", p);
	// printf("%f\n", p);
	// printf("%lf\n", p);
	// printf("%lld\n", p);
	// printf("%s\n", p);
	// printf("%p\n", p);

	// printf("%d\n", q);
	// printf("%f\n", q);
	// printf("%lf\n", q);
	// printf("%lld\n", q);
	// printf("%s\n", q);
	// printf("%p\n", q);

	// printf("%d\n", a);
	// printf("%f\n", a);
	// printf("%lf\n", a);
	// printf("%lld\n", a);
	// // printf("%s\n", a);
	// printf("%p\n", a);

	// printf("%d\n", b);
	// printf("%f\n", b);
	// printf("%lf\n", b);
	// printf("%lld\n", b);
	// // printf("%s\n", b);
	// printf("%p\n", b);

	// printf("%d\n", i);
	// printf("%f\n", i);
	// printf("%lf\n", i);
	// printf("%lld\n", i);
	// // printf("%s\n", i);
	// printf("%p\n", i);

	return 0;
}


/*
 * 1. wartość: p to wskaźnik na adres pierwszego elementu tablicy tab
 * 2. wartość: q to wskaźnik na adres pierwszego elementu tablicy tab
 * 3. wartość: a to wskaźnik na adres pierwszego elementu tablicy tab ; niezgodne z regułami programowania bo a powi
 * 4. wartość: b to wskaźnik na adres pierwszego elementu znajdującego się poza tablicą ; nieokreślony wynik
 * 5. wartość: p to wskażnik na adres ósmego elementu znajcujądego się poza tablicą ; nieokreślony wynik
 * 6. wartość: 29_04_kwestionariusz.c:9:6: error: lvalue required as increment operand
 * 7. wartość: a = 0 - ósmy element tablicy będący zerem
 * 8. wartość: b wychodzi poza tablicę - wartość nieokreślona, niezgodne z regułami programowania, kompilator nie zwraca błędów związanych z przekorczniem pamięci
 * 9. wartość: p to wartość od p + rozmiar typu(long int)
 * 10. wartość: jak powyżej
 * 11. wartość: q to jak powyżej
 * 12. wartość: q = wartość p + rozmiar typu(long int) +2
 * 13. wartość: 29_04_kwestionariusz.c:9:8: error: stray ‘\342’ in program
  i = q ��� p;
        ^
29_04_kwestionariusz.c:9:9: error: stray ‘\200’ in program
  i = q ��� p;
         ^
29_04_kwestionariusz.c:9:10: error: stray ‘\223’ in program
  i = q ��� p;
          ^
29_04_kwestionariusz.c:9:4: warning: assignment makes integer from pointer without a cast [-Wint-conversion]
  i = q – p;
    ^
29_04_kwestionariusz.c:9:12: error: expected ‘;’ before ‘p’
  i = q – p;
            ^
 * 14. wartość: pierwszy element poza tablicą - ostatni element tablicy = 1
 * 15. wartość: 
 * 16. wartość: 
 * 17. wartość: 
 * 18. wartość: 
 * 19. wartość: 
 * 20. wartość: 
 */ 

// 1.    *p = tab;
// 2.    q = &tab;
// 3.    a = *tab;
// 4.    b = *(&a + 1);
// 5.    p = tab + 8;
// 6.    q = ++tab;
// 7.    a = *(tab + 8);
// 8.    a = *(p + 16);
// 9.    ++p;
// 10.    p++;
// 11.    q = p++;
// 12.    q = 2 + p++;
// 13.    i = q – p;
// 14.    i = ++p - tab;
// 15.    q = tab + p;
// 16.    *tab + 4;
// 17.    a = *(tab+4);
// 18.    *(tab+2) = a++;
// 19.    *p++ = b;
// 20.    *++p = b;