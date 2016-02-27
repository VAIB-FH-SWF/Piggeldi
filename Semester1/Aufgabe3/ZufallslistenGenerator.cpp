/* 
 * File:   Zufallsgenerator.cpp
 * Author: fredde
 * 
 * Created on 25. Oktober 2015, 09:51
 * Compiler g++
 */

#include "ZufallslistenGenerator.h"
#include "cstdlib"
#include "DefaultZufallsgenerator.h"
#include <math.h>

ZufallslistenGenerator::ZufallslistenGenerator(int feldGroesse)
{
    this->listeMitZufallszahlen = doubleVector (feldGroesse, -1); // Erzeugt einen Vector mit 0 fuer alle Felder
    
    this->generator = new DefaultZufallsgenerator();
    
}
ZufallslistenGenerator::ZufallslistenGenerator(int feldGroesse, AbstractZufallsgenerator* generator) {
    
    this->listeMitZufallszahlen = doubleVector (feldGroesse, -1); // Erzeugt einen Vector mit 1- fuer alle Felder
    
    this->generator = generator; // Setzen des Customzufallsgenerator
}

doubleVector& ZufallslistenGenerator::erzeugeListe(int grenze)
{
    for (doubleVector::size_type i = 0; i != this->listeMitZufallszahlen.size() ; i++ )
    {
        this->listeMitZufallszahlen[i] = fmod(this->generator->rand(), grenze);
    }
    
    return this->listeMitZufallszahlen;
}

doubleVector& ZufallslistenGenerator::erzeugeListe()
{
    for (doubleVector::size_type i = 0; i != this->listeMitZufallszahlen.size() ; i++ )
    {
        this->listeMitZufallszahlen[i] = this->generator->rand();
    }
    
    return this->listeMitZufallszahlen;
}