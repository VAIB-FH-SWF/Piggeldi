#include "Mitarbeiter.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Haupteinstiegspunkt
int main()
{
    // Maximale Anzahl Mitarbeiter setzen
    const int ANZMITARBEITER = 100;
    Mitarbeiter bunchOfMitarbeiter[ANZMITARBEITER];
    // Filestream Objekt zum einlesen der Datei erstellen
    ifstream ifs;
    ifs.open("/Users/private/Studium/C++/Piggeldi/Semester2/Aufgabe4.2/personen.dat");
    if(!ifs)
    {	// Programm mit Fehler beenden
        cerr << "Fehler beim Lesen aus Datei" << endl;
        exit(1);
    }
    // Zaehler fuer die tatsichliche Mitarbeiteranzahl
    int anzahlMitarbeiter = 0;
    // Temporaere Variablen zum einlesen deklarieren
    string identnummer, nachname, vorname, abteilung, durchwahl;
    // Mitarbeiter einlesen
    while(ifs >> identnummer >> nachname >> vorname >> abteilung >> durchwahl)
    {
        // Mitarbeiter Daten setzen
        bunchOfMitarbeiter[anzahlMitarbeiter].set_identnummer(identnummer);
        bunchOfMitarbeiter[anzahlMitarbeiter].set_nachname(nachname);
        bunchOfMitarbeiter[anzahlMitarbeiter].set_vorname(vorname);
        bunchOfMitarbeiter[anzahlMitarbeiter].set_abteilung(abteilung);
        bunchOfMitarbeiter[anzahlMitarbeiter].set_durchwahl(durchwahl);

        // Anzahl gelesener Saetze erhoehen
        anzahlMitarbeiter++;

        // Wenn die Anzahl >= der Maxmimalen Mitarbeiter Anzahl ist, das einlesen beenden
        if(anzahlMitarbeiter >= ANZMITARBEITER)
        {
            break;
        }
    }
    // Dateistream schliessen
    ifs.close();

    // Mitarbeiter ausgeben
    for(int i = 0; i < anzahlMitarbeiter; i++)
    {
        cout << setw(4) << i << ": ";
        bunchOfMitarbeiter[i].print();
    }

    return 0;
}