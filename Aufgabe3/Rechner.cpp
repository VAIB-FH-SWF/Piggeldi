/* 
 * File:   Rechner.cpp
 * Author: fredde
 * 
 * Created on 25. Oktober 2015, 10:59
 * Compiler g++
 */

#include "Rechner.h"

Rechner::Rechner(doubleVector& theVector)
{
    liste = theVector;
    
    this->mittelWert = 0.00;
    this->kleinsterWert = 0.00;
    this->groessterWert = 0.00;
    
    this->listeAuswerten();
}

double Rechner::ermittelArithmetischesMittel()
{
    return this->mittelWert;
}

double Rechner::ermittelGroesstenWert()
{
    return this->groessterWert;       
}

double Rechner::ermittelKleinstenWert()
{
    return this->kleinsterWert;
}

void Rechner::listeAuswerten()
{
    for (doubleVector::size_type loopIterator = 0; loopIterator < liste.size(); loopIterator ++ )
    {
        double aktuelleZahl = liste[loopIterator];
        this->mittelWert += aktuelleZahl;
        
        //startwert fur die kleinste Zahl festlegen
        if (loopIterator == 0)
        {
            this->kleinsterWert = aktuelleZahl;
        }
        
        //Ermitteln der groessten Zahl
        if (this->groessterWert < aktuelleZahl)
        {
            this->groessterWert = aktuelleZahl;
        }
        
        //Ermitteln der kleinsten Zahl
        if (this->kleinsterWert > aktuelleZahl)
        {
            this->kleinsterWert = aktuelleZahl;
        }
     
    }
    this->mittelWert =  this->mittelWert/(double)liste.size();
}