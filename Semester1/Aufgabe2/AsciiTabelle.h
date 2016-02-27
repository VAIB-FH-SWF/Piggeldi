/* 
 * File:   AsciiiTabelle.h
 * Author: fredde
 *
 * Created on 10. Oktober 2015, 18:23
 */

#ifndef ASCIIITABELLE_H
#define	ASCIIITABELLE_H

#include <iostream>
#include <iomanip>

class AsciiTabelle
{
public:

    /**
     * Zeichnet die Asciitabelle aus Ausgabe 2.1.
     */
    static void zeichneTabelle();

private:

    /**
     * Zeichnet ein einzelnes AsciiZeichen in den Tabellenkontext
     * @param zeichen
     */
    static void zeichneAsciiZeichen(char zeichen);

};

#endif	/* ASCIIITABELLE_H */

