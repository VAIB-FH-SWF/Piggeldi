/* 
 * File:   main.cpp
 * Author: fredde
 *
 * Created on 26. Oktober 2015, 16:48
 */

#include <iomanip> 
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

/*
 Enumeration welche die 3 Zustaende definiert
 */
enum ZUSTAND {
    ZIFFER, LEER, BUCHSTABE
};

int main() {

    //Deklaration der Variablen und mit 0 vorbelegen
    int summeZiffer = 0, summeBuchstaben = 0, summeWoerter = 0, summeZahl = 0;

    //Auszulesende Datei
    string dateiname = "text.txt";
    //Die Datei offenen
    std::ifstream dateiStream(dateiname);

    //Datei konnte geoeffent werden
    if (dateiStream) {

        string text = "";

        cout << "Analysiere folgenden Text:" << endl;

        //Jede Zeile im text auslesen
        while (getline(dateiStream, text)) {

            cout << text << endl;

            ZUSTAND zustand = LEER;

            //Fuer jedes Zeichen im Text...
            for (std::string::size_type i = 0; i < text.size(); ++i) {

                // Ziffer...
                if (isdigit(text[i])) {

                    summeZiffer = summeZiffer + 1;

                    if (LEER == zustand) {
                        summeZahl++;
                        zustand = ZIFFER;
                    } else if (BUCHSTABE == zustand) {
                        cerr << "\nFEHLER: Buchstaben und Zahlen sind an Stelle " << i + 1 << " verschmischt\n";
                        exit(1);
                    }
                    //Buchstaben        
                } else if (isalpha(text[i])) {

                    summeBuchstaben = summeBuchstaben + 1;

                    if (LEER == zustand) {
                        summeWoerter++;
                        zustand = BUCHSTABE;
                    } else if (ZIFFER == zustand) {
                        cerr << "\nFEHLER: Buchstaben und Zahlen sind an Stelle " << i + 1 << " verschmischt\n";
                        exit(1);
                    }
                //Leerzeichen        
                } else if (isspace(text[i])) {

                    zustand = LEER;
                }
            }
        }
    } else {
        cerr << "Datei " << dateiname << " konnte nicht gefunden/geoeffnet werden \n";
    }

    cout << "Analyse Ergebnis:" << endl;

    cout << setw(6) << summeZiffer << " Ziffern\n";
    cout << setw(6) << summeBuchstaben << " Buchstaben\n";
    cout << setw(6) << summeWoerter << " Woerter\n";
    cout << setw(6) << summeZahl << " Zahlen\n";

    return 0;
}