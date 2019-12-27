#include <iostream>
#include "userInterface.hpp"
#include "idiotTolerance.hpp"
#include "game8vs8.hpp"
#include "game16vs16.hpp"

#ifndef functionality_hpp
#define functionality_hpp

using namespace std;

void Menu(string lang = "EN") {
    int choose = 3;
    PrintMenu();
    choose = ChooseGamemode();
    switch (choose)
    {
    case 1:
        Game8vs8();
        break;
    
    case 2:
        Game16vs16();
        break;

    case 3:
        exit(0);
        break;

    default:
        exit(0);
        break;
    }
}

#endif