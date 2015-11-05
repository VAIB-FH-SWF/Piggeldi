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

int main() {
    
    //Deklaration der Variablen
    int summeZiffer, summeBuchstaben, summeWoerter, summeZahl;
    
    string dateiname = "test.txt";
    //Die Datei offenen
    std::ifstream dateiStream(dateiname);
    //Alles mit 0 vorbelegen
    summeZiffer = summeBuchstaben = summeWoerter = summeZahl = 0;
    //Datei konnte geoeffent werden
    if (dateiStream) {

        string text = "";
        //Jede Zeile im text auslesen
        while (getline(dateiStream, text)) {
            
            cout << text << endl;

            bool zustandBuchstaben = true; //Zustand fuer die Buchstaben
            bool zustandZiffer = true; //Zustand fuer die Ziffer
            
            //Fuer jeden Char im text...
            for (std::string::size_type i = 0; i < text.size(); ++i) {
                
                // Ziffer...
                if (isdigit(text[i])) {
                    summeZiffer = summeZiffer + 1;

                    if (zustandZiffer) {
                        summeZahl++;
                        zustandZiffer = false;
                    }

                    //Pruefen ob der naechste Eintrag auch eine Ziffer ist
                    if (isalpha(text[i + 1]) && text[i + 1] != '\0') {
                        cerr << "\nFEHLER: Buchstaben und Zahlen sind an Stelle " << i + 1 << " verschmischt\n";
                        exit(1);
                    }
                //Buchstaben        
                } else if (isalpha(text[i])) {

                    summeBuchstaben = summeBuchstaben + 1;
                    if (zustandBuchstaben) {
                        summeWoerter++;
                        zustandBuchstaben = false;
                    }

                    //Pruefen ob der naechste Eintrag auch ein Buchstabe ist
                    if (isdigit(text[i + 1]) && text[i + 1] != '\0') {
                        cerr << "\nFEHLER: Buchstaben und Zahlen sind an Stelle " << i + 1 << " verschmischt\n";
                        exit(1);
                    }
                //Leerzeichen        
                } else if (isspace(text[i])) {

                    zustandBuchstaben = true;
                    zustandZiffer = true;
                }
            }
        }
    } else {
        cerr << "Datei " << dateiname << " konnte nicht gefunden/geoeffnet werden \n";
    }

    cout << setw(6) << summeZiffer << " Ziffern\n";
    cout << setw(6) << summeBuchstaben << " Buchstaben\n";
    cout << setw(6) << summeWoerter << " Woerter\n";
    cout << setw(6) << summeZahl << " Zahlen\n";

    return 0;

}
// ---------- end of function main ----------