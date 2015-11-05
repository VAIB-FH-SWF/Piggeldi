/*
 * =======================================================================
 * Filename: 	Summation.h
 * Description:	AufgabenNr1
 * Version:	 	1.0
 * Created:	 	09:56:19
 * Revision:	    none
 * Compiler:     g++
 * Author:       fredde
 * Organization: none
 * ===============================================================================
 */

#ifndef PRAKTIKUM_SUMMATION_H
#define PRAKTIKUM_SUMMATION_H

#include <string>
#include <iostream>

#include "SummationResult.h"

class Summation {

public:

    Summation();
    Summation(int pgrenze);

    double harmonischeReihe();
    double alternierendeReihe();
    double leibnizscheReihe();
    double geometrischeReihe();
    fred::SummationResult* geometrischeReiheOhneGrenze();
};


#endif //PRAKTIKUM_SUMMATION_H
