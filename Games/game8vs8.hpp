#include "userInterface.hpp"
#include "jumpingPawnsFunctions.hpp"

void StartField8vs8(char GameField[8][8], pawnsCordinates Pawns[16]) {
    for(int r = 0; r < 8; r++) {
        for(int c = 0; c < 8; c++) {
            GameField[r][c] = 'N';
        }
    }
    pawnsCordinates initial;
    for(int i = 0; i < 8; i++){
        GameField[6 + i % 2][i] = 'B'; initial.x = 6 + i % 2; initial.y = i;
        Pawns[i+8] = initial;
        GameField[0 + i % 2][i] = 'W'; initial.x = 0 + i % 2;
        Pawns[i] = initial;
    }
}

void ChangePawns(pawnsCordinates Pawns[16], coordinates move) {
    for(int i = 0; i < 16; i++) {
        if(Pawns[i].x == move.xS and Pawns[i].y == move.yS) {
            Pawns[i].x = move.xD; Pawns[i].y = move.yD; return;
        } 
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

bool IsPossibleToMoveForward(char GameField[8][8], pawnsCordinates Pawns[16], int whoseMove, string &hint) {
    string source = "", destination = "";
    
    if(whoseMove % 2 == 0) {    /*for white pawns*/
        for(int i = 0; i < 8; i++) {
            if(/*not necessary to check if x >= 0*/ Pawns[i].x + 1 < 8 and (Pawns[i].y - 1 >= 0 and GameField[Pawns[i].x + 1][Pawns[i].y - 1] == 'N')) {
                hint = "Possible move: " + CoordinatesTranslationToString(Pawns[i].x, Pawns[i].y) + " --> " + CoordinatesTranslationToString(Pawns[i].x + 1, Pawns[i].y - 1);
                return true;
            }
            if(Pawns[i].x + 1 < 8 and (Pawns[i].y + 1 >= 0 and GameField[Pawns[i].x + 1][Pawns[i].y + 1] == 'N'))  {
                hint = "Possible move: " + CoordinatesTranslationToString(Pawns[i].x, Pawns[i].y) + " --> " + CoordinatesTranslationToString(Pawns[i].x + 1, Pawns[i].y + 1);
                return true;
            }

            if(/*not necessary to check if x >= 0*/ Pawns[i].x + 2 < 8 and (Pawns[i].y - 2 >= 0 and GameField[Pawns[i].x + 2][Pawns[i].y - 2] == 'N' and GameField[Pawns[i].x + 1][Pawns[i].y - 1] != 'N')) {
                hint = "Possible move: " + CoordinatesTranslationToString(Pawns[i].x, Pawns[i].y) + " --> " + CoordinatesTranslationToString(Pawns[i].x + 2, Pawns[i].y - 2);
                return true;
            }
            if(Pawns[i].x + 2 < 8 and (Pawns[i].y + 2 >= 0 and GameField[Pawns[i].x + 2][Pawns[i].y + 2] == 'N' and GameField[Pawns[i].x + 1][Pawns[i].y + 1] != 'N'))  {
                hint = "Possible move: " + CoordinatesTranslationToString(Pawns[i].x, Pawns[i].y) + " --> " + CoordinatesTranslationToString(Pawns[i].x + 2, Pawns[i].y + 2);
                return true;
            }
        }
        hint = "There is no possible forward move. Try back ...";
        return false;
    } else {                    /*for black pawns*/
        for(int i = 8; i < 16; i++) {
            if(/*not necessary to check if x < 8*/ Pawns[i].x - 1 >= 0 and (Pawns[i].y - 1 >= 0 and GameField[Pawns[i].x - 1][Pawns[i].y - 1] == 'N')) {
                hint = "Possible move: " + CoordinatesTranslationToString(Pawns[i].x, Pawns[i].y) + " --> " + CoordinatesTranslationToString(Pawns[i].x - 1, Pawns[i].y - 1);
                return true;
            }
            if(Pawns[i].x - 1 >= 0 and (Pawns[i].y + 1 >= 0 and GameField[Pawns[i].x - 1][Pawns[i].y + 1] == 'N'))  {
                hint = "Possible move: " + CoordinatesTranslationToString(Pawns[i].x, Pawns[i].y) + " --> " + CoordinatesTranslationToString(Pawns[i].x - 1, Pawns[i].y + 1);
                return true;
            }

            if(/*not necessary to check if x < 8*/ Pawns[i].x - 2 >= 0 and (Pawns[i].y - 2 >= 0 and GameField[Pawns[i].x - 2][Pawns[i].y - 2] == 'N' and GameField[Pawns[i].x - 1][Pawns[i].y - 1] != 'N')) {
                hint = "Possible move: " + CoordinatesTranslationToString(Pawns[i].x, Pawns[i].y) + " --> " + CoordinatesTranslationToString(Pawns[i].x - 2, Pawns[i].y - 2);
                return true;
            }
            if(Pawns[i].x - 2 >= 0 and (Pawns[i].y + 2 >= 0 and GameField[Pawns[i].x - 2][Pawns[i].y + 2] == 'N' and GameField[Pawns[i].x - 1][Pawns[i].y + 1] != 'N'))  {
                hint = "Possible move: " + CoordinatesTranslationToString(Pawns[i].x, Pawns[i].y) + " --> " + CoordinatesTranslationToString(Pawns[i].x - 2, Pawns[i].y + 2);
                return true;
            }
        }
        hint = "There is no possible forward move. Try back ...";
        return false;
    }
}

bool BackMovePossibility(char GameField[8][8], int xS, int yS, int xD, int yD, int whoseMove) {
    if(whoseMove % 2 == 0) {
        if(xS == xD + 1 and (yS == yD + 1 or yS == yD - 1)) return true;
    } else {
        if(xS == xD - 1 and (yS == yD + 1 or yS == yD - 1)) return true;
    }
}

bool RecursiveJumpsPossibilityWhite(char GameField[8][8], int xS, int yS, int xD, int yD, bool &jumpPossibiilityFlag, int level) {
    /* cout << "start recursive" << endl; */
    if(jumpPossibiilityFlag) {/* cout << "jumpPossFlag = true" << endl; */ return true;}
    //if(xS == xD and yS != yD) {cout << "fuck false" << endl; return false;}
    if(xS == xD and yS == yD) {jumpPossibiilityFlag = true; /* cout << "jumpPossFlag change to true" << endl;*/ return true;}
    if(/*only addition - not necessary to check limes infimum*/xS+2<8 and yS+2<8 and GameField[xS+2][yS+2] == 'N' and GameField[xS+1][yS+1] != 'N') {/*cout << "path1" << endl;*/ return RecursiveJumpsPossibilityWhite(GameField, xS+2, yS+2, xD, yD, jumpPossibiilityFlag, level+1);}
    if(xS+2<8 and yS-2>=0 and GameField[xS+2][yS-2] == 'N' and GameField[xS+1][yS-1] != 'N') {/*cout << "path2" << endl;*/ return RecursiveJumpsPossibilityWhite(GameField, xS+2, yS-2, xD, yD, jumpPossibiilityFlag, level+1);}
    if(!jumpPossibiilityFlag and level == 0) {/*cout << "return false" << endl;*/ return false;}
}

bool RecursiveJumpsPossibilityBlack(char GameField[8][8], int xS, int yS, int xD, int yD, bool &jumpPossibiilityFlag, int level) {
    /*cout << "start recursive" << endl;*/
    if(jumpPossibiilityFlag) {/*cout << "jumpPossFlag = true" << endl;*/ return true;}
    //if(xS == xD and yS != yD) {cout << "fuck false" << endl; return false;}
    if(xS == xD and yS == yD) {jumpPossibiilityFlag = true; /*cout << "jumpPossFlag change to true" << endl;*/ return true;}
    if(xS-2>=0 and yS+2<8 and GameField[xS-2][yS+2] == 'N' and GameField[xS-1][yS+1] != 'N') {/*cout << "path1" << endl;*/ return RecursiveJumpsPossibilityBlack(GameField, xS-2, yS-2, xD, yD, jumpPossibiilityFlag, level+1);}
    if(xS-2>=0 and yS-2>=0 and GameField[xS-2][yS-2] == 'N' and GameField[xS-1][yS-1] != 'N') {/*cout << "path2" << endl;*/ return RecursiveJumpsPossibilityBlack(GameField, xS-2, yS+2, xD, yD, jumpPossibiilityFlag, level+1);}
    if(!jumpPossibiilityFlag and level == 0) {/*cout << "return false" << endl;*/ return false;}
}

bool IsMovePossible(char GameField[8][8], pawnsCordinates Pawns[16], int whoseMove, coordinates move, string &hint) {        //input ONLY correct coordinates [A-H] and [1-8]
    bool jumpPossibiilityFlag = false;  int level = 0;
    if(move.xS % 2 != move.yS % 2 or move.xD % 2 != move.yD % 2 /*field from or to is not in game*/) {cout << "field from or to is not in game" << '\n'; return false;}  
    if(GameField[move.xD][move.yD] != 'N' or GameField[move.xS][move.yS] == 'N' /*move to not empty field or move from empty field*/) {cout << "move to not empty field or move from empty field" << '\n'; return false;}
    if(GameField[move.xS][move.yS] == 'W' and whoseMove % 2 != 0 /*black try to move white*/) {cout << "black try to move white" << '\n'; return false;}
    if(GameField[move.xS][move.yS] == 'B' and whoseMove % 2 != 1 /*white try to move black*/) {cout << "white try to move black" << '\n'; return false;} 
    if((whoseMove % 2 == 0 and move.xS == move.xD) or (whoseMove % 2 == 1 and move.xS == move.xD)) {cout << "try not move" << '\n'; return false;}
    if(IsPossibleToMoveForward(GameField, Pawns, whoseMove, hint)) {
        if((whoseMove % 2 == 0 and move.xS >= move.xD) or (whoseMove % 2 == 1 and move.xS <= move.xD)) {cout << "try not back" << '\n'; return false;}
        if((move.xD == move.xS + 1 and (move.yD == move.yS + 1 or move.yD == move.yS - 1)) /*one field move for white and one field move for black*/
        or (move.xD == move.xS - 1 and (move.yD == move.yS + 1 or move.yD == move.yS - 1))) return true;
        if(move.xS % 2 == move.xD % 2 and move.yS % 2 == move.yD % 2 and whoseMove % 2 == 0) {
            return RecursiveJumpsPossibilityWhite(GameField, move.xS, move.yS, move.xD, move.yD, jumpPossibiilityFlag, level);
        } else if(move.xS % 2 == move.xD % 2 and move.yS % 2 == move.yD % 2 and whoseMove % 2 == 1) {
            return RecursiveJumpsPossibilityBlack(GameField, move.xS, move.yS, move.xD, move.yD, jumpPossibiilityFlag, level);
        }
    } else {
        return BackMovePossibility(GameField, move.xS, move.yS, move.xD, move.yD, whoseMove);       
    }
}

void PlayerMove(char GameField[8][8], pawnsCordinates Pawns[16], int whoseMove, bool &endGameFlag) {
    coordinates move; int tryMoves = 0; string hint = "";
    bool moveDoneFlag = true;
    while(moveDoneFlag and endGameFlag) {
        PrintGameField(GameField);
        WhoseMove(whoseMove);
        move = PlayerInput(endGameFlag);
        IsPossibleToMoveForward(GameField, Pawns, whoseMove, hint);
        if(IsMovePossible(GameField, Pawns, whoseMove, move, hint)) {
            GameField[move.xS][move.yS] = 'N';
            ChangePawns(Pawns, move);
            if(whoseMove % 2 == 0) {GameField[move.xD][move.yD] = 'W';}
            else {GameField[move.xD][move.yD] = 'B';}
            moveDoneFlag = false;
        }
        if(tryMoves >= 3) cout << hint << endl;     /*hint after third mistake*/
        tryMoves++; cout << '\n';
    }
}

//END PLAYER MOVE GROUP

int Game8vs8() {
    char GameField[8][8];
    pawnsCordinates Pawns[16];
    bool endGameflag = true;
    gameData dataForGame;
    dataForGame.whoseMove = 0;
    dataForGame.endFlag = true;
    dataForGame.whoWins = "";
    StartField8vs8(GameField, Pawns);

    // testPrintGameField(GameField);
    // testPrintPawns(Pawns);

    while(dataForGame.endFlag and endGameflag) {
        PlayerMove(GameField, Pawns, dataForGame.whoseMove, endGameflag );
        IsWinner(GameField, dataForGame);
        // testPrintPawns(Pawns);
        dataForGame.whoseMove++;
    }

    return 0;
}
