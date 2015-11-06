/* 
 * File:   Rechner.h
 * Author: fredde
 *
 * Created on 10. Oktober 2015, 19:59
 */

#ifndef RECHNER_H
#define	RECHNER_H

#include "Dreieck.h"

class Rechner
{
public:

    /**
     * Multipliziert erst die uergebene Gleitkommtzahl mit dem Faktor 0.1639
     * und devidiert das Ergebnis wiederrum mit dem Faktor 0.1639
     * @return das neue Ergebnis
     */
    static float multiDividiereMitGleitkommaZahl(float riesigeGleitkommeZahl);

    /**
     * Ermittelt die Dreiecksflaeche mit dem Satz von Heron mit
     * der ersten Darstellung aus dem Lernbrief
     * @param dreieck (Das zu berechnenden Dreieck)
     * @return die Fläche des Dreiecks
     */
    static double ermittelDreiecksflaecheMitHeron1(Dreieck& dreieck);

    /**
     * Ermittelt die Dreieckesflaeche mit dem Satz von Heron mit
     * der zweiten Darstellung aus dem Lernbrief
     * @param dreieck (Das zu berechnenden Dreieck)
     * @return die Fläche des Dreiecks
     */
    static double ermittelDreiecksflaecheMitHeron2(Dreieck& dreieck);

private:

};

#endif	/* RECHNER_H */

