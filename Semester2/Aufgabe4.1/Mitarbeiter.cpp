#include <iostream>
#include <iomanip>
#include "Mitarbeiter.h"

using namespace std;
/**
 * Standard Konstruktor
 */
Mitarbeiter::Mitarbeiter(string id,
                         string nachname,
                         string vorname,
                         string abteilung,
                         string durchwahl)
{
    this->p = new Person();
    this->p->identnummer = id;
    this->p->nachname = nachname;
    this->p->vorname = vorname;
    this->p->abteilung = abteilung;
    this->p->durchwahl = durchwahl;
}

/**
 * Kopierkonsturktor 
 */
Mitarbeiter::Mitarbeiter(const Mitarbeiter &other)
{
    *this = other;
}

/**
 * Destruktor
 */
Mitarbeiter::~Mitarbeiter()
{
    delete this->p;
}

/**
 * Zuweisungsoperator 
 */
Mitarbeiter& Mitarbeiter::operator = (const Mitarbeiter &other)
{
    // Nur kopieren wenn nicht das gleiche Objekt
    if(this != &other)
    {
        delete this->p;

        this->p = new Person;
        p->identnummer = other.get_identnummer();
        p->nachname = other.get_nachname();
        p->vorname = other.get_vorname();
        p->abteilung = other.get_abteilung();
        p->durchwahl = other.get_durchwahl();
    }

    return *this;
}

/** 
 * Methode zum Ausgeben der Daten 
 */
void Mitarbeiter:: print()
{
    cout << right;
    cout << setw(9) << p->identnummer << ", "
    << p->nachname << ", "
    << p->vorname << ", "
    << p->abteilung << ", "
    << p->durchwahl << endl;
}