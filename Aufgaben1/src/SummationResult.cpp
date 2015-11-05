/*
 * =======================================================================
 * Filename: 	SummationResult.cpp
 * Description:	AufgabenNr1
 * Version:	 	1.0
 * Created:	 	14:31:14
 * Revision:	    none
 * Compiler:     g++
 * Author:       fredde
 * Organization: none
 * ===============================================================================
 */
#include "SummationResult.h"

namespace fred {

SummationResult::SummationResult(long double ergebnis, int summenZaehler) {
	this->result = ergebnis;
	this->summenZaehler = summenZaehler;
}

long double SummationResult::getResult() {
	return this->result;
}
int SummationResult::getSumZaehler() {
	return this->summenZaehler;
}

} /* namespace std */
