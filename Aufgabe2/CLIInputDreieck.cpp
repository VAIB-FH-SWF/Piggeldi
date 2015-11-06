/* 
 * File:   CLIInputDreieck.cpp
 * Author: fredde
 * 
 * Created on 11. Oktober 2015, 08:39
 * Compiler g++
 */

#include "CLIInputDreieck.h"
#include <iostream>

CLIInputDreieck::CLIInputDreieck() {
}

double CLIInputDreieck::leseDreieckSeite(std::string seitenBezeichnung) {
    
    std::cout << "Bitte geben Sie die Flaeche fuer die Dreiecksseite " << seitenBezeichnung << " ein" << std::endl;
    
    return leseGleitkommaZahl();
}

Dreieck CLIInputDreieck::leseDreieckFlaechen() {
    
    double seiteA = leseDreieckSeite("A");
    double seiteB = leseDreieckSeite("B");
    double seiteC = leseDreieckSeite("C");
    
    return Dreieck (seiteA, seiteB, seiteC);
}
