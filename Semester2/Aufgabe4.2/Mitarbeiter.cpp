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
    // Nur kopieren wenn nicht die gleiche adresse im speicher
    if(this != &other)
    {
        //Erzeuge eine tiefe kopie des Mitarbeiters
        delete this->p;

        this->p = new Person;
        this->p->identnummer = other.get_identnummer();
        this->p->nachname = other.get_nachname();
        this->p->vorname = other.get_vorname();
        this->p->abteilung = other.get_abteilung();
        this->p->durchwahl = other.get_durchwahl();
    }

    return *this;
}

/** 
 * Methode zum Ausgeben der Daten 
 */
void Mitarbeiter::print()
{
    cout << right;
    cout << setw(9) << this->p->identnummer << ", "
    << this->p->nachname << ", "
    << this->p->vorname << ", "
    << this->p->abteilung << ", "
    << this->p->durchwahl << endl;
}