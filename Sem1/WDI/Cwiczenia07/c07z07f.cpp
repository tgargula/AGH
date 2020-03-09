//Tresc oczywista - wyznacznik rekurencyjnie Laplace

#include<iostream>

using namespace std;

const int N = 4;

int wyzn(int t[N][N], int w, int * k, int st = N) {
	if (st == 1) {
		return t[w][k[0]];
	}
	int sum = 0;
	int* kk = new int[st - 1];
	for (int i = 0; i < st; i++) {							//petla po kolumnach
		for (int j = 0, l = 0; j < st - 1; j++, l++) {		//generka nowych kolumn
			if (l == i) l++;
			kk[j] = k[l];
		}
		sum += (1 - 2 * ((i) % 2)) * t[w][k[i]] * wyzn(t, w + 1, kk, st - 1);
	}
	delete[] kk;
	return sum;
}

int main() {
	int t[N][N];
	cout << "Wpisz macierz:\n";
	for (int i = 0; i < N; i++) {
		cout << "W" << i << ": ";
		for (int j = 0; j < N; j++) {
			cin >> t[i][j];
		}
	}
	int* k = new int[N];
	for (int i = 0; i < N; i++) {
		k[i] = i;
	}
	cout << wyzn(t, 0, k);
	delete[] k;
}
