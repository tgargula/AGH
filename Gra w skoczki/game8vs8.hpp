#include "userInterface.hpp"

struct gameData {
    int whoseMove;
    bool endFlag;
    string whoWins;
};

struct coordinates {
    int xS; int yS;
    int xD; int yD;
};

void StartField8vs8(char GameField[8][8]) {
    for(int r = 0; r < 8; r++) {
        for(int c = 0; c < 8; c++) {
            GameField[r][c] = 'N';
        }
    }
    for(int i = 0; i < 8; i++){
        GameField[6 + i % 2][i] = 'B';
        GameField[0 + i % 2][i] = 'W';
    }
}

void WhoseMove(int whoseMove) {
    if(whoseMove %2 == 0) {
            cout << "White move ..." << '\n';
        } else {
            cout << "Black move ..." << '\n';
        }
}

gameData IsWinner(char GameField[8][8], gameData &dataForGame) {
    if(dataForGame.whoseMove < 24) {
        dataForGame.endFlag = true;
        return dataForGame;
    }
    bool blackWinFlag = true, whiteWinFlag = true;
    for(int w = 0; w < 8; w++) {
        if(GameField[7 - w % 2][w] != 'B') whiteWinFlag = false;
        if(GameField[1 - w % 2][w] != 'W') blackWinFlag = false;
    }
    if(blackWinFlag and whiteWinFlag) {
        dataForGame.endFlag = false; dataForGame.whoWins = "DRAW!"; return dataForGame;
    } else if(whiteWinFlag) {
        dataForGame.endFlag = false; dataForGame.whoWins = "White WIN!"; return dataForGame;
    } else if(blackWinFlag) {
        dataForGame.endFlag = false; dataForGame.whoWins = "Black WIN!"; return dataForGame;
    }
    return dataForGame;
}

//PLAYER MOVE GROUP

coordinates coordinatesTranslation(string userInputS, string userInputD) {
    coordinates input;
    input.xS = (int)userInputS[1] - 49;
    input.yS = (int)userInputS[0] - 65;
    input.xD = (int)userInputD[1] - 49;
    input.yD = (int)userInputD[0] - 65;
    return input;
}

coordinates PlayerInput() {
    string userInputS = "", userInputD = "";
    cout << "Input coordinates: " << '\n';
    cin >> userInputS;          //A1 , H6 , B8 ect...
    cin >> userInputD;
    //idiot tolerance please here
    return coordinatesTranslation(userInputS, userInputD);
}

bool RecursiveJumpsPossibilityWhite(char GameField[8][8], int xS, int yS, int prevxS, int prevyS, int xD, int yD, bool &jumpPossibiilityFlag) {
    if(xS<0 and xS>=8 and yS<0 and yS>=8) return false;
    if(GameField[(xS+prevxS)/2][(yS+prevyS)/2] == 'N') return false;
    if(jumpPossibiilityFlag) return true;
    if(xS == xD and yS != yD) return false;
    if(xS == xD and yS == yD) {jumpPossibiilityFlag = true; return true;}
    return RecursiveJumpsPossibilityWhite(GameField, xS+2, yS+2, xS, yS, xD, yD, jumpPossibiilityFlag) 
    or RecursiveJumpsPossibilityWhite(GameField, xS+2, yS-2, xS, yS, xD, yD, jumpPossibiilityFlag);
}

bool RecursiveJumpsPossibilityBlack(char GameField[8][8], int xS, int yS, int prevxS, int prevyS, int xD, int yD, bool &jumpPossibiilityFlag) {
    if(xS<0 and xS>=8 and yS<0 and yS>=8) return false;
    if(GameField[(xS+prevxS)/2][(yS+prevyS)/2] == 'N') return false;
    if(jumpPossibiilityFlag) return true;
    if(xS == xD and yS != yD) return false;
    if(xS == xD and yS == yD) {jumpPossibiilityFlag = true; return true;}
    return RecursiveJumpsPossibilityBlack(GameField, xS-2, yS-2, xS, yS, xD, yD, jumpPossibiilityFlag) 
    or RecursiveJumpsPossibilityBlack(GameField, xS-2, yS+2, xS, yS, xD, yD, jumpPossibiilityFlag);
}

bool IsMovePossible(char GameField[8][8], int whoseMove, coordinates move) {        //input ONLY correct coordinates [A-H] and [1-8]
    bool jumpPossibiilityFlag = false;  int level = 0;
    if(move.xS % 2 != move.yS % 2 or move.xD % 2 != move.yD % 2 /*field from or to is not in game*/) {cout << "field from or to is not in game" << '\n'; return false;}  
    if(GameField[move.xD][move.yD] != 'N' or GameField[move.xS][move.yS] == 'N' /*move to not empty field or move from empty field*/) {cout << "move to not empty field or move from empty field" << '\n'; return false;}
    if(GameField[move.xS][move.yS] == 'W' and whoseMove % 2 != 0 /*black try to move white*/) {cout << "black try to move white" << '\n'; return false;}
    if(GameField[move.xS][move.yS] == 'B' and whoseMove % 2 != 1 /*white try to move black*/) {cout << "white try to move black" << '\n'; return false;} 
    if((whoseMove % 2 == 0 and move.xS >= move.xD) or (whoseMove % 2 == 1 and move.xS <= move.xD)) {cout << "try to back or try to not move" << '\n'; return false;}
    if(move.xD == move.xS + 1 and (move.yD == move.yS + 1 or move.yD == move.yS - 1)) return true;
    if(move.xS % 2 == move.xD % 2 and move.yS % 2 == move.yD % 2 and whoseMove % 2 == 0) {
        return RecursiveJumpsPossibilityWhite(GameField, move.xS, move.yS, move.xS, move.yS, move.xD, move.yD, jumpPossibiilityFlag);
    } else if(move.xS % 2 == move.xD % 2 and move.yS % 2 == move.yD % 2 and whoseMove % 2 == 1) {
        return RecursiveJumpsPossibilityBlack(GameField, move.xS, move.yS, move.xS, move.yS, move.xD, move.yD, jumpPossibiilityFlag);
    }
}

void PlayerMove(char GameField[8][8], int whoseMove) {
    coordinates move;
    bool moveDoneFlag = true;
    while(moveDoneFlag) {
        move = PlayerInput();
        if(IsMovePossible(GameField, whoseMove, move)) {
            GameField[move.xS][move.yS] = 'N';
            if(whoseMove % 2 == 0) {GameField[move.xD][move.yD] = 'W';}
            else {GameField[move.xD][move.yD] = 'B';}
            moveDoneFlag = false;
        }
    }
}

//END PLAYER MOVE GROUP

int Game8vs8() {
    char GameField[8][8];
    gameData dataForGame;
    dataForGame.whoseMove = 0;
    dataForGame.endFlag = true;
    dataForGame.whoWins = "";
    StartField8vs8(GameField);
    PrintGameField(GameField);

    //testPrintGameField(GameField);

    while(dataForGame.endFlag) {
        WhoseMove(dataForGame.whoseMove);
        PlayerMove(GameField, dataForGame.whoseMove);
        PrintGameField(GameField);
        IsWinner(GameField, dataForGame);
        dataForGame.whoseMove++;
    }

    return 0;
}
