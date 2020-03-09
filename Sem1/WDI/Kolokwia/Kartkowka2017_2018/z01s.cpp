#include <iostream>

using namespace std;

string Konwersja(int liczba, int podstawa, string wynik = "", string s1 = "") {
    while(liczba > 0) {
        if(liczba % podstawa <= 9) {s1 = char(liczba % podstawa + 48);}
        else {s1 = char(liczba % podstawa + 55);}
        wynik = s1 + wynik;
        liczba /= podstawa;
    }
    return wynik;
}

bool Porownanie(string liczba1, string liczba2, int podstawa) {
    bool czy_wystepuje[16] = {false};
    for(int i = 0; i < liczba1.size(); i++) {
        czy_wystepuje[int(liczba1[i]-48)] = true;
    }
    for(int i = 0; i < liczba2.size(); i++) {
        if(czy_wystepuje[int(liczba2[i]-48)]) return false;
    }
    return true;
}

int main(){
    int liczba1, liczba2; cin >> liczba1 >> liczba2;
    for(int i = 2; i <= 16; i++) {
        if(Porownanie(Konwersja(liczba1, i), Konwersja(liczba2, i), i)) {
            cout << i;
            return 0;
        } 
    }
    cout << "NIE"; return 0;

}