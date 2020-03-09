/*
7.Zbiór mnogościowy zawierający napisy jest reprezentowany w postaci
jednokierunkowej listy. Napisy w łańcuchu są uporządkowane leksykograficznie.
Proszę napisać stosowne definicje typów oraz funkcję dodającą napis
do zbioru. Do funkcji należy przekazać wskaźnik do listy oraz wstawiany
napis, funkcja powinna zwrócić wartość logiczną wskazującą,
czy w wyniku operacji moc zbioru uległa zmianie.
*/

#include <iostream>

using namespace std;

struct node {
    string s;
    node * next;
};

void output (node * f) {
    while (f != NULL) {
        cout << f->s << " ";
        f = f->next;
    }
    cout << endl;
}

bool lexicographicalOrder(string a, string b) {
    if (a == b) return false;
    for (int i = 0; i < min(a.size(),b.size()); i++) {
        if(char(a[i]) > char(b[i])) return false;
        if(char(a[i]) < char(b[i])) return true;
    }
    return a.size() < b.size();
}

void insertFirst (node *&f, string s) {
    node * r = new node;
    r->s = s;
    r->next = f;
    f = r;
}

void insertToTheMiddle (node * f, string s) {
    node * r = new node;
    r->s = s;
    r->next = f->next;
    f->next = r;
}

bool insertString (node *&f, string s) {
    if (f == NULL) {
        insertFirst(f,s);
        return true;
    }

    node * prev = NULL;
    node * F = f;
    while (f != NULL and lexicographicalOrder(f->s, s)) {
        prev = f;
        f = f->next;
    }

    if (prev == NULL) {
        insertFirst(f,s);
        return true;
    }
    if (f == NULL or f->s != s) { 
        insertToTheMiddle(prev,s);
        f = F;
        return true;
    }
    if (f->s == s) {
        f = F;
        return false;
    }
}

void test() {
    if(!lexicographicalOrder("ab","ab")) cout << 1; else cout << 0;
    if(!lexicographicalOrder("slonce","hello")) cout << 1; else cout << 0;
    if(lexicographicalOrder("hello","slonce")) cout << 1; else cout << 0;
    if(!lexicographicalOrder("abcde","abc")) cout << 1; else cout << 0;

    node * f = NULL;
    insertFirst(f,"there");
    insertFirst(f,"hello");
    insertFirst(f,"acdf");
    insertFirst(f,"abc");
    insertFirst(f,"aaa");

    output(f);

    if(!insertString(f,"hello")) cout << 1; else cout << 0;
    if(insertString(f,"aaa")) cout << 1; else cout << 0;
    cout << " "; output(f);
    if(insertString(f,"generalkenobi")) cout << 1; else cout << 0;
    cout << " "; output(f);

    node * s = NULL;
    if (insertString(s,"hello")) cout << 1; else cout << 0;
    if (insertString(s,"there")) cout << 1; else cout << 0;
    if (insertString(s,"general")) cout << 1; else cout << 0;
    if (insertString(s,"kenobi")) cout << 1; else cout << 0;

    cout << " "; output(s);
}

int main() {
    
    test();
    
    return 0;
}