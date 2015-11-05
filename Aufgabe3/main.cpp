/* 
 * File:   main.cpp
 * Author: fredde
 *
 * Created on 25. Oktober 2015, 09:12
 */

#include <cstdlib>
#include "Aufgabenhandler.h"

using namespace std;
/*
 * Haupteinstiegspunkts
 */
int main(int argc, char** argv) {
    
    Aufgabenhandler::zeigeAufgabeZufallsliste();
    
    Aufgabenhandler::zeigeAufgabeZahlenliste();
    
    Aufgabenhandler::zeigeAufgabePseudoZufallsZahl();
    
    Aufgabenhandler::zeigeAufgabePeriodenlange();
}

