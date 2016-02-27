/* 
 * File:   main.cpp
 * Author: fredde
 *
 * Created on 26. Oktober 2015, 16:48
 */

#include <iomanip>   
#include <iostream>

using namespace std;

/*
 Enumeration welche die 3 Zustaende definiert
 */
enum ZUSTAND {
    ZIFFER, LEER, BUCHSTABE
};

int main() {
    int maxstring = 256; // Puffergroesse
    char text[maxstring]; // Eingabepuffer
    char c; // Hilfsvariable
    int textIterator = 0, summeWoerter = 0; // Schleifenzaehler,Buchstabezaehler

    ZUSTAND zustand = LEER;

    cout << "Geben Sie eine Textzeile ein: ";

    // jedes Zeichen einzeln einlesen
    while ((c = cin.get()) != '\n') {
        text[textIterator] = c;
        textIterator = textIterator + 1;
    }
    text[textIterator] = '\0';

    cout << "Der eingegebene Text lautet: '" << text << "'\n";


    for (textIterator = 0; text[textIterator] != '\0'; textIterator += 1) {
        if (isspace(text[textIterator])) {
            zustand = LEER;
            continue;
        }
        if (LEER == zustand) {
            summeWoerter++;
        }
        zustand = BUCHSTABE;
    }

    cout << setw(6) << summeWoerter << " Woerter\n";

    return (0);
}
