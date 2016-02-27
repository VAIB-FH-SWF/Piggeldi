/* 
 * File:   main.cpp
 * Author: fredde
 *
 * Created on 10. Oktober 2015, 18:17
 */

#include <cstdlib>
#include "AufgabenHandler.h"


using namespace std;

/*
 * Haupteinstiegspunkt in das Programm
 */
int main(int argc, char** argv) {
    
    AufgabenHandler::zeigeAufgabeAsciiTabelle();
    
    AufgabenHandler::zeigeAufgabeFloatBerechnung();
    
    AufgabenHandler::zeigeAufgabeDreiecksFlaechenBerechnung();
    
    //Wir muessen hier keinen Speicher freigeben, weil ich nichts mit new allociert habe
    
    return 0;
}

