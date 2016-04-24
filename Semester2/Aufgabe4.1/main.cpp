#include "Mitarbeiter.h"
#include <iostream>

using namespace std;

// Haupteinstiegspunkt
int main()
{
    // Mitarbeiter deklarieren (Alle werte auf Default)
    Mitarbeiter alice;
    // Mitarbeiter mit Default-Werten ausgeben
    cout << "Mitarbeiter nach Initialisierung: " << endl;
    alice.print();

    // Werte zuweisen
    // Das ordnungsgemaesse Funktionieren aller Methoden ist durch
    // einfache Verwendung im Hauptprogramm nachzuweisen
    alice.set_identnummer("10004242");
    alice.set_nachname("Müller");
    alice.set_vorname("Alice");
    alice.set_abteilung("MS Racing Team");
    alice.set_durchwahl("15");

    cout << "Mitarbeiter nach Wertzuweisung: " << endl;
    alice.print();

    // Kopierkonstruktor testen
    Mitarbeiter bob(alice);
    cout << "Kopierter Mitarbeiter mit Konstruktor: " << endl;
    bob.set_vorname("Bob");
    bob.print();

    // Zuweisungsoperator testen
    Mitarbeiter bobsBrother;
    bobsBrother = bob;
    cout << "Kopierter Mitarbeiter mit Zuweisung: " << endl;
    bobsBrother.print();

    return 0;
}