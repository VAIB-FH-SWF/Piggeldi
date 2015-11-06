/* 
 * File:   AufgabenHandler.h
 * Author: fredde
 *
 * Created on 11. Oktober 2015, 09:47
 */

#ifndef AUFGABENHANDLER_H
#define	AUFGABENHANDLER_H

#include <iostream>
#include <array>
#include "AsciiTabelle.h"
#include "Dreieck.h"
#include "Rechner.h"
#include "CLIInputDreieck.h"

using namespace std;

class AufgabenHandler
{
public:

    /**
     * Schreibt die geforderte AsciiTabelle aus Aufgabe 2.1.
     * in der Konsole 
     */
    static void zeigeAufgabeAsciiTabelle();

    /**
     * Macht eine Multiplikation/Division mit großen Floatzahlen
     * und schreibt die Ausgabe in der Konsole 
     */
    static void zeigeAufgabeFloatBerechnung();

    /**
     * Nimmt Seitenlaengen eines Dreiecks über die Konsoleneingabe 
     * entgegen und berechnet die Flaeche des Dreiecks nach zwei verschiedenen 
     * Schreibweisen des Satzes von Heron
     */
    static void zeigeAufgabeDreiecksFlaechenBerechnung();

private:

};

#endif	/* AUFGABENHANDLER_H */

