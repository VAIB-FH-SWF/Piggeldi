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

#include "Summation.h"
#include "SummationResult.h"
int grenze = 1000;
using namespace std;

/**
 * Berechnet die Harmonischereihe bis zur Grenze
 * @return double
 */
double Summation::harmonischeReihe() {

    double ergebnis = 0.0;

    for (double i = 1.0; i < grenze; i++)
    {
        ergebnis += (1.0 / i);
    }
    return ergebnis;
}

/**
 * Berechnet die Alternierendereihe bis zur Grenze
 * @return double
 */
double Summation::alternierendeReihe() {

    double ergebnis = 0.0;

    int v = -1;
    for (double i = 1.0; i < grenze; i++)
    {
        v = -v;

        ergebnis += v * (1.0/i);

    }

    return ergebnis;
}
/**
 * Berechnet die Leibnizschereihe bis zur Grenze
 * @return double
 */
double Summation::leibnizscheReihe() {

    double ergebnis = 0.0;

    int v = -1;

    for (double i = 1.0; i < (grenze*2); i = i +2)
    {
        v = -v;

        ergebnis += v * ( 1.0/ i);
    }

    return ergebnis;
}
/**
 * Ermittelt die Geometrischereihe
 * @return
 */
double Summation::geometrischeReihe() {

    double ergebnis = 0.0;

    double multiplikator = 1.0;

    for (double i = 1.0; i < grenze; i++)
    {
    	ergebnis += 1.0/multiplikator;
    	multiplikator = multiplikator * 2;
    }

    return ergebnis;
}
/**
 * Default Konstruktor
 */
Summation::Summation() {
    grenze = 1000;
}
/**
 * Konstruktur mit oberer Grenze
 * @param pgrenze
 */
Summation::Summation(int pgrenze) {
  grenze = pgrenze;
}
/**
 * Berechnet die geometrische Reihe bis sich das Ergebnis
 * nicht mehr veraendert
 * @return double
 */
fred::SummationResult* Summation::geometrischeReiheOhneGrenze() {

    double ergebnis = 0.0;
    double i = 1.0;
    double altesErgebnis = -1;

    int zaehlerSum  = 0;

    while (ergebnis != altesErgebnis)
    {
    	altesErgebnis = ergebnis;
        ergebnis += (1/ i);
        i = i * 2;

        zaehlerSum ++;
    }

    return new fred::SummationResult(ergebnis,zaehlerSum);
}
