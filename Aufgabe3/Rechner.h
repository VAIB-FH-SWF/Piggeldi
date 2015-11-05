/* 
 * File:   Rechner.h
 * Author: fredde
 *
 * Created on 25. Oktober 2015, 10:59
 */

#ifndef RECHNER_H
#define	RECHNER_H

#include <vector>
#include "Defines.h"

class Rechner
{
public:
    /**
     * Erzeugt den Rechner mit dem Vector als berechnungsgrundlage
     * @param theVector
     */
    Rechner(doubleVector& theVector);

    /**
     * Ermittelt das Arithmetisches Mittel aus dem Vector
     * @return 
     */
    double ermittelArithmetischesMittel();
    /**
     * Ermittelt den kleinsten Wert aus dem Vector
     * @return 
     */
    double ermittelKleinstenWert();
    /**
     * Ermittelt den groessten Wert aus dem Vector
     * @return 
     */
    double ermittelGroesstenWert();

private:

    void listeAuswerten();

    double kleinsterWert, groessterWert, mittelWert;

    doubleVector liste;
};

#endif	/* RECHNER_H */

