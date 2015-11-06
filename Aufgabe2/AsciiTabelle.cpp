/* 
 * File:   AsciiiTabelle.cpp
 * Author: fredde
 * 
 * Created on 10. Oktober 2015, 18:23
 */

#include "AsciiTabelle.h"

using namespace std;

 void AsciiTabelle::zeichneAsciiZeichen(char zeichen) {
    int zeichenIndex = (int) zeichen; //Beinhaltet den Index des Zeichen in der AsciiTabelle

    //Ausgabe Octalzahl
    cout << setfill('0') << setw(3) << fixed << oct << zeichenIndex << "\t";
    //Ausgabe Dezimalzahl
    cout << setfill('0') << setw(3) << fixed << dec << zeichenIndex << "\t";
    //Ausgabe Hexadezimalzahl
    cout << setfill('0') << setw(3) << fixed << hex << zeichenIndex << "\t";

    // In der Asciitabelle liegen an den Indezen zwischen 0 und 32 sowie 127 nur Steuerzeichen
    // hier wird anstatt des Steuerzeichens einfach "..." ausgegeben
    if ((zeichenIndex >= 0 && zeichenIndex <= 32) || zeichenIndex == 127) {
        cout << "...";
    } else {
        cout << zeichen;
    }

    cout << "\t";
}

 void AsciiTabelle::zeichneTabelle() {
     
    cout << "***  ASCII-Tabelle  ***" << endl; 
     
    int anzahlSpalten = 4; // Definition der Spaltenanzahl
    int anzahlZeilen = 32; // Definition der Zeilenanzahl

    cout << "Okt\tDez\tHex\tZch\tOkt\tDez\tHex\tZch\tOkt\tDez\tHex\tZch\tOkt\tDez\tHex\tZch\t\n";

    // Pro Zeile...
    for (int zeile = 0; zeile < anzahlZeilen; zeile++) {
        //... 4 Spalten
        for (int spalte = 0; spalte < anzahlSpalten; spalte++) {

            // Zeichen ermitteln
            char zeichen = zeile + (spalte * anzahlZeilen);

            zeichneAsciiZeichen(zeichen);
        }

        // Ende der Zeilenausgabe
        cout << endl;
    }
}

