/* 
 * File:   AufgabenHandler.cpp
 * Author: fredde
 * 
 * Created on 11. Oktober 2015, 09:47
 * Compiler g++
 */

#include "AufgabenHandler.h"

void AufgabenHandler::zeigeAufgabeAsciiTabelle() {

    AsciiTabelle::zeichneTabelle();

}

void AufgabenHandler::zeigeAufgabeFloatBerechnung() {

    float riesigeFloatZahl = 1000000.00;

    cout << "Vor der Berechnung:" << fixed << setprecision(8) << riesigeFloatZahl << endl;

    float riesigeFloatZahlNachBerechnung = Rechner::multiDividiereMitGleitkommaZahl(riesigeFloatZahl);

    cout << "Nach der Berechnung:" << fixed << setprecision(8) << riesigeFloatZahlNachBerechnung << endl;

    if (riesigeFloatZahl == riesigeFloatZahlNachBerechnung) {
        cout << "Beide Zahlen sind gleich nach der multiplikation/division" << endl;
    }
}

void AufgabenHandler::zeigeAufgabeDreiecksFlaechenBerechnung() {

    //Falls wir uns die Eingabe sparen wollen.
    //Dreieck dreieck1 = Dreieck (1.0,1.0,1.0);
    //Dreieck dreieck2 = Dreieck (3.0,4.0,5.0);

    // Die gewünschten Dreiecke aus CLI entgegennehmen
    Dreieck dreieck1 = CLIInputDreieck().leseDreieckFlaechen();
    Dreieck dreieck2 = CLIInputDreieck().leseDreieckFlaechen();

    // Die Dreiecke ins Array packen
    array <Dreieck, 2> dreiecke{
        {dreieck1, dreieck2}
    };


    // Fuer jedes Dreieck...
    for (Dreieck dreieck : dreiecke) {
        // ... die Flache berechnen
        double calcFlaeche1 = Rechner::ermittelDreiecksflaecheMitHeron1(dreieck);
        double calcFlaeche2 = Rechner::ermittelDreiecksflaecheMitHeron2(dreieck);

        if ((calcFlaeche1 < 0) || (calcFlaeche2 < 0)) {
            cout << "Das Dreieck" << dreieck.print() << " ist kein Dreieck" << endl;
        } else {

            cout << "Die Dreieckflaeche des Dreiecks " << dreieck.print();

            //Beide Formeln das haben das gleiche Ergebnis ermittelt
            if (calcFlaeche1 == calcFlaeche2) {

                cout << " betraegt :" << calcFlaeche1 << endl;
            } else {
                cout << " betraegt :" << "(" << calcFlaeche1 << "/" << calcFlaeche2 << ")" << endl;
            }
        }
    }


}



