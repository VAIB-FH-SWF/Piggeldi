/*
 * =======================================================================
 * Filename: 	AufgabenNr1.h
 * Description:	AufgabenNr1
 * Version:	 	1.0
 * Created:	 	09:56:19
 * Revision:	    none
 * Compiler:     g++
 * Author:       fredde
 * Organization: none
 * ===============================================================================
 */

#include <iostream>
#include <iomanip>
#include "Summation.h"
#include "SummationResult.h"
using namespace std;

int main() {


	cout << "Praktikum ’Programmierung mit C++ 1’ / Blatt 1 / Aufgabe 1\n";
	int n = 1000; // Anzahl der Summanden
	int width = 10; // Ausgabebreite summe
	int precision = 	5; // Nachkommastellen summe

	Summation summation (n);

	cout << "Harmonische Reihe :";
	cout << fixed << setw(width) << setprecision(precision) << summation.harmonischeReihe() << "\n";

	cout << "Alternierende Reihe :";
	cout << fixed << setw(width) << setprecision(precision) << summation.alternierendeReihe() << "\n";

	cout << "Leibnizsche Reihe :";
	cout << fixed << setw(width) << setprecision(precision) << summation.leibnizscheReihe() << "\n";

	cout << "Geometrische Reihe mit Summand: " << n << ":";
	cout << fixed << setw(width) << setprecision(precision) << summation.geometrischeReihe() << "\n";

	cout << "Geometrische Reihe unendlich :";

	fred::SummationResult *result = summation.geometrischeReiheOhneGrenze();

	cout << fixed << setw(width) << setprecision(15) << (double)result->getResult() << " mit Zahler " << result->getSumZaehler() << "\n";


	return 0;
}
