#include <iostream>

#ifndef idiotTolerance_hpp
#define idiotTolerance_hpp

using namespace std;

int ChooseGamemode(int i = 3) {
    string input;
    while(i > 0) {  //cout << "i'm in choosegamemode" << '\n';
        getline(cin, input);
        if(input.size() == 1 and (int)input[0] >= 49 and (int)input[0] <= 51) {return (int)input[0] - 48;}
        else if(input == "exit") {return 3;}
        else if(input == "8 vs 8" or input == "eight") {return 8;}
        i--;
    }
    return 0;
}

#endif