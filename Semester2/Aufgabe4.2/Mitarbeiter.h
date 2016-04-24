//
// Created by Private on 19.04.16.
//

#ifndef AUFGABE4_MITARBEITER_H
#define AUFGABE4_MITARBEITER_H

#include <string>
#include "Person.h"

using namespace std;

class Mitarbeiter {

public:
    //==============LIFECYCLE=============================================================

    Mitarbeiter(string identnummer = "-",
                string nachname    = "-",
                string vorname     = "-",
                string abteilung   = "-",
                string durchwahl   = "-");
    Mitarbeiter(const Mitarbeiter &other);
    ~Mitarbeiter();

    //==============ACCESSORS=============================================================
    string get_identnummer   () const { return p->identnummer; }
    string get_nachname      () const { return p->nachname; }
    string get_vorname       () const { return p->vorname; }
    string get_abteilung     () const { return p->abteilung; }
    string get_durchwahl     () const { return p->durchwahl; }
    //Gibt eine Formatierte Beschreibung des Mitarbeiters aus
    void   print             ();

    //==============ACCESSORS=============================================================
    void set_identnummer   (string value) { p->identnummer = value; }
    void set_nachname      (string value) { p->nachname = value; }
    void set_vorname       (string value) { p->vorname = value; }
    void set_abteilung     (string value) { p->abteilung = value; }
    void set_durchwahl     (string value) { p->durchwahl = value; }

    //==============OPERATORS=============================================================
    Mitarbeiter& operator = ( const Mitarbeiter &other);

private:
    //==============DATA MEMBERS==========================================================
    Person   *p;
};


#endif //AUFGABE4_MITARBEITER_H
