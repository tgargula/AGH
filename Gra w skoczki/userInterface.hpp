#include <iostream>

#ifndef userInterface_hpp
#define userInterface_hpp

using namespace std;
// ifstream lang_part("language.json");
// lang_part >> language;



// string Language() {
//     cout << language["EN"]["chooseLanguage"]
// }

void PrintMenu() {
    cout << "Choose gamemode: " << endl;
    cout << "1) 8 vs 8" << '\n' << "2) 16 vs 16 (beta)" << '\n' << "3) exit" << endl;
}

void PrintGameField(char GameField[8][8]) {
    cout << "X ";
    for(int i = 0; i < 8; i++) cout << (char)(i + 65) << " ";
    cout << "X" << '\n'; 
    for(int r = 0; r < 8; r++) {
        cout << r + 1 << " ";
        for(int c = 0; c < 8; c++) {
            if(GameField[r][c] == 'N') {cout << "  ";}
            else {cout << GameField[r][c] << " ";}
        }
        cout << r + 1 << "\n";
    }
    cout << "X ";
    for(int i = 0; i < 8; i++) cout << (char)(i + 65) << " ";
    cout << "X" << '\n'; 
}

void testPrintGameField(char GameField[8][8]) {
    cout << "X ";
    for(int i = 0; i < 8; i++) cout << (char)(i + 65) << " ";
    cout << "X" << '\n'; 
    for(int r = 0; r < 8; r++) {
        cout << r + 1 << " ";
        for(int c = 0; c < 8; c++) {
            cout << "(" << r << ", " << c << ") ";
        }
        cout << r + 1 << "\n";
    }
    cout << "X ";
    for(int i = 0; i < 8; i++) cout << (char)(i + 65) << " ";
    cout << "X" << '\n';
}

#endif