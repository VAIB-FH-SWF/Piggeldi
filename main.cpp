/* 
 * File:   main.cpp
 * Author: fredde
 *
 * Created on 26. Oktober 2015, 16:48
 */

#include <iomanip>   
#include <iostream>

using namespace std;

int main() {
    int maxstring = 256; // Puffergroesse
    char text[maxstring]; // Eingabepuffer
    char c; // Hilfsvariable
    int textIterator, summeWoerter; // Schleifenzaehler,Buchstabezaehler
    bool istSpace = true;

    cout << "Geben Sie eine Textzeile ein: ";

    textIterator = 0;
    // jedes Zeichen einzeln einlesen
    while ((c = cin.get()) != '\n') {
        text[textIterator] = c;
        textIterator = textIterator + 1;
    }
    text[textIterator] = '\0';

    cout << "Der eingegebene Text lautet: '" << text << "'\n";

    summeWoerter = 0;
    // Woerter und andere Zeichen werden als WORT
    // nur SPACE, Tabs usw. werden als LEER gezaehlt
    for (textIterator = 0; text[textIterator] != '\0'; textIterator += 1) {
        if (isspace(text[textIterator])) {
            istSpace = true;
        } else {
            if (istSpace) {
                summeWoerter++;
            }

            istSpace = false;
        }
    }
    cout << setw(6) << summeWoerter << " Woerter\n";

    return (0);
}
