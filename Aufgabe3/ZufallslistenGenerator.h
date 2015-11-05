/* 
 * File:   Zufallsgenerator.h
 * Author: fredde
 *
 * Created on 25. Oktober 2015, 09:51
 */

#ifndef ZUFALLSGENERATOR_H
#define	ZUFALLSGENERATOR_H

#include <vector>
#include "Defines.h"
#include "DefaultZufallsgenerator.h"
#include "AbstractZufallsgenerator.h"

class ZufallslistenGenerator
{
public:
    /**
     * Erzeugt den Zufallsgenerator mit der feldgroesse
     * @param feldGroesse
     */
    ZufallslistenGenerator(int feldGroesse);

    /**
     * Erzeugt den Listengenererator mit der feldgroesse sowie einem
     * custom Zufallsgenerator welcher einer Subclass des AbstractZufallsgenerator ist
     * @param feldGroesse
     * @param generator
     * @return 
     */
    ZufallslistenGenerator(int feldGroesse, AbstractZufallsgenerator* generator);

    /**
     * Erzeugt einen Vector gefüllt mit Zufallszahlen < grenze. 
     * Defaultgenerator ist cstdlib.rand
     * @param Grenzwert der Zufallszahlen
     * @return Vector<double
     */
    doubleVector& erzeugeListe(int grenze);

    /**
     * Erzeugt einen gefuellt mit Zufallszahlen
     * @return 
     */
    doubleVector& erzeugeListe();

private:
    doubleVector listeMitZufallszahlen;
    AbstractZufallsgenerator* generator;
};

#endif	/* ZUFALLSGENERATOR_H */

