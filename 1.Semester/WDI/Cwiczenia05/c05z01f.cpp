#include<iostream>

using namespace std;

struct ulamek {
	long long l;
	long long m;
};

void skracanieQ(ulamek& u) {
	long long a = abs(u.l);
	long long b = abs(u.m);
	long long c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	u.l /= a;
	u.m /= a;
}

ulamek dodawanieQ(ulamek a, ulamek b) {
	ulamek wynik;
	wynik.l = a.l * b.m + a.m * b.l;
	wynik.m = a.m * b.m;
	skracanieQ(wynik);
	return wynik;
}

ulamek odejmowanieQ(ulamek a, ulamek b) {
	ulamek wynik;
	wynik.l = a.l * b.m - a.m * b.l;
	wynik.m = a.m * b.m;
	skracanieQ(wynik);
	return wynik;
}

ulamek mnozenieQ(ulamek a, ulamek b) {
	ulamek wynik;
	wynik.l = a.l * b.l;
	wynik.m = a.m * b.m;
	skracanieQ(wynik);
	return wynik;
}

ulamek dzielenieQ(ulamek a, ulamek b) {
	ulamek wynik;
	wynik.l = a.l * b.m;
	wynik.m = a.m * b.l;
	skracanieQ(wynik);
	return wynik;
}

ulamek potegowanieQ(ulamek a, ulamek potega) {
	ulamek wynik;
	if (potega.l * potega.m < 0) {
		long long temp = a.l;
		a.l = a.m;
		a.m = temp;
		potega.l = abs(potega.l);
		potega.m = abs(potega.m);
	}
	wynik.l = pow(a.l, double(potega.l)/potega.m);
	wynik.m = pow(a.m, double(potega.l)/potega.m);
	skracanieQ(wynik);
	return wynik;
}

void wypisywanieQ(ulamek a) {
	cout << a.l << "/" << a.m;
}

void wczytywanieQ(ulamek& a) {
	char slash;
	cin >> a.l >> slash >> a.m;
}

int main() {
	ulamek a, b;
	char c = 1;
	cout << "Legenda:\na -------- dodawanie\ns -------- odejmowanie\nm -------- mnozenie\nd -------- dzielenie\np -------- potegowanie\nw -------- wypisywanie"
		<< "\ndefault -- wczytaj liczbe\n0 -------- wyjdz";
	cin >> c;
	while (c != 0) {
		switch (c) {
		case 'a': {
			wczytywanieQ(b);
			wypisywanieQ(a = dodawanieQ(a, b));
			break;
		}
		case 's': {
			wczytywanieQ(b);
			wypisywanieQ(a = odejmowanieQ(a, b));
			break;
		}
		case 'm': {
			wczytywanieQ(b);
			wypisywanieQ(a = mnozenieQ(a, b));
			break;
		}
		case 'd': {
			wczytywanieQ(b);
			wypisywanieQ(a = dzielenieQ(a, b));
			break;
		}
		case 'p': {
			wczytywanieQ(b);
			wypisywanieQ(a = potegowanieQ(a, b));
			break;
		}
		case'w': {
			wypisywanieQ(a);
			break;
		}
		default: {
			wczytywanieQ(a);
		}
		}
		cin >> c;
	}
}
