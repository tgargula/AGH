#include <iostream>

#ifndef jumpingPawnsFunctions_hpp
#define jumpingPawnsFunctions_hpp

using namespace std;

struct gameData {
    int whoseMove;
    bool endFlag;
    string whoWins;
};

struct coordinates {
    int xS; int yS;
    int xD; int yD;
};

struct pawnsCordinates {
    int x, y;
};

coordinates CoordinatesTranslationToInt(string userInputS, string userInputD) {
    coordinates input;
    input.xS = (int)userInputS[1] - 49;
    input.yS = (int)userInputS[0] - 65;
    input.xD = (int)userInputD[1] - 49;
    input.yD = (int)userInputD[0] - 65;
    return input;
}

string CoordinatesTranslationToString(int x, int y) {
    string humanReadableCordinates = "";
    humanReadableCordinates.push_back((char)(y + 65)); 
    humanReadableCordinates.push_back((char)(x + 49));
    return humanReadableCordinates;
}

coordinates PlayerInput(bool &endGameFlag) {
    coordinates falseValue; falseValue.xD = falseValue.xS = falseValue.yD = falseValue.yS = -1;
    string userInputS = "", userInputD = "";
    cout << "Input coordinates: " << '\n';
    cin >> userInputS;          //A1 , H6 , B8 ect...
    cin >> userInputD;
    if(userInputS == "exit" or userInputD == "exit" or userInputS == "EXIT" or userInputD == "EXIT") {
        endGameFlag = false;
        return falseValue;
    }
    //idiot tolerance please here
    return CoordinatesTranslationToInt(userInputS, userInputD);
}

#endif