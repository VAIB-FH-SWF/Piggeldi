/* 
 * File:   CLI.cpp
 * Author: fredde
 * 
 * Created on 10. Oktober 2015, 21:46
 * Compiler g++
 */

#include "CLIInput.h"
#include <iomanip>
#include <iostream>

CLIInput::CLIInput() {
}

int CLIInput::leseIntegerZahl() {
    return (int) leseGleitkommaZahl();
}

double CLIInput::leseGleitkommaZahl() {
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

std::string CLIInput::leseText() {

    std::string eingabe;

    std::cin >> eingabe;

    if (std::cin.fail()) {
        std::cin.clear();

        std::cout << "Fehler bei der Eingabe" << std::endl;
    }

    return eingabe;
}

CLIInput::~CLIInput() {
}

