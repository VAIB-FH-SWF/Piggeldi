/* 
 * File:   Aufgabenhandler.cpp
 * Author: fredde
 * 
 * Created on 25. Oktober 2015, 15:45
 */

#include "Aufgabenhandler.h"
#include "VectorOutput.h"
#include "Defines.h"
#include "DefaultZufallsgenerator.h"
#include "Rechner.h"
#include "Zahlendatei.h"
#include "LehmerKongruenzZufallsgenerator.h"
#include "ZufallslistenGenerator.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Aufgabenhandler::zeigeAufgabePseudoZufallsZahl() {

    cout << "Aufgabe 3.3" << endl;

    //Erzeugen eines Customzufallsgenerator mit dem die Zufallswerte berechnet werden sollen
    LehmerKongruenzZufallsgenerator *customGenerator = new LehmerKongruenzZufallsgenerator();

    //Listengenerator mit Anzahl Zahlen sowie mit dem Zufallsgenerator
    ZufallslistenGenerator customListGenerator = ZufallslistenGenerator(10, customGenerator);

    doubleVector listMitZufallsWerten = customListGenerator.erzeugeListe();

    //Ausgabe der Liste
    Vectoroutput::printVector(listMitZufallsWerten, 1);

    delete (customGenerator);
}

void Aufgabenhandler::zeigeAufgabeZufallsliste() {

    cout << "Aufgabe 3.1" << endl;

    ZufallslistenGenerator generator = ZufallslistenGenerator(100);

    doubleVector listMitZufallsWerten = generator.erzeugeListe(51);

    Vectoroutput::printVector(listMitZufallsWerten, 10);

    Rechner rechner = Rechner(listMitZufallsWerten);

    cout << "Arithmetisches Mittel " << setprecision(2) << rechner.ermittelArithmetischesMittel() << endl;
    cout << "Groesster Wert " << setprecision(2) << rechner.ermittelGroesstenWert() << endl;
    cout << "Kleinster Wert " << setprecision(2) << rechner.ermittelKleinstenWert() << endl;
}

void Aufgabenhandler::zeigeAufgabeZahlenliste() {

    cout << "Aufgabe 3.2" << endl;

    std::string dateiname = "daten-3-2.txt";

    Zahlendatei datei = Zahlendatei(dateiname);

    doubleVector listeMitZahlen = datei.leseDatei();

    //Einkommentiere wenn die komplette Liste wieder angezeigt werden soll
    //CLIOutput::printGleitkommaVector(listeMitZahlen, 1);

    Rechner rechner = Rechner(listeMitZahlen);

    cout << "Arithmetisches Mittel " << fixed << setprecision(4) << rechner.ermittelArithmetischesMittel() << endl;
    cout << "Groesster Wert " << fixed << setprecision(4) << rechner.ermittelGroesstenWert() << endl;
    cout << "Kleinster Wert " << fixed << setprecision(4) << rechner.ermittelKleinstenWert() << endl;
}

void Aufgabenhandler::zeigeAufgabePeriodenlange() {

    cout << "Aufgabe 3.4." << endl;

    LehmerKongruenzZufallsgenerator *customGenerator = new LehmerKongruenzZufallsgenerator();

    //Listengenerator mit Anzahl Zahlen sowie mit dem Zufallsgenerator.
    //32769 ist die maximal anzahl der zufaelligen zahlen bei diesem algorithmus
    ZufallslistenGenerator customListGenerator = ZufallslistenGenerator(32769, customGenerator);

    doubleVector zahlenListe = customListGenerator.erzeugeListe();

    for (doubleVector::size_type i = 0; i < zahlenListe.size(); i++) {

        if (zahlenListe[i] == 0) {
            cout << "Nach " << i + 1 << " von " << zahlenListe.size() << " Zufallszahlen befindet sich die 0" << endl;
        }
    }
}