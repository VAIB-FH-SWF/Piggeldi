/* 
 * File:   CLI.cpp
 * Author: fredde
 * 
 * Created on 10. Oktober 2015, 21:46
 * Compiler g++
 */

#include "CLIBasic.h"
#include <iomanip>
#include <iostream>

CLIBasic::CLIBasic() {
}

int CLIBasic::leseIntegerZahl() {
    return (int) leseGleitkommaZahl();
}

double CLIBasic::leseGleitkommaZahl() {
    double eingabeWert;


    std::cin >> eingabeWert;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');

        std::cout << "Die Eingabe war nicht nummerisch \n" << std::endl;

        //Nochmal die Eingabe lesen
        return leseGleitkommaZahl();
    }
    return eingabeWert;
}

std::string CLIBasic::leseText() {

    std::string eingabe;

    std::cin >> eingabe;

    if (std::cin.fail()) {
        std::cin.clear();

        std::cout << "Fehler bei der Eingabe" << std::endl;
    }

    return eingabe;
}

CLIBasic::~CLIBasic() {
}

