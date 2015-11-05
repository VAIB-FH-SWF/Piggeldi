/*
 * =======================================================================
 * Filename: 	SummationResult.h
 * Description:	AufgabenNr1
 * Version:	 	1.0
 * Created:	 	14:31:14
 * Revision:	    none
 * Compiler:     g++
 * Author:       fredde
 * Organization: none
 * ===============================================================================
 */
#ifndef SUMMATIONRESULT_H_
#define SUMMATIONRESULT_H_

namespace fred {


class SummationResult {
	long double result;
	int summenZaehler;

public:
	/**
	 * Init das SummationResultObject mit den pflichten Parametern ergebnis/summenZaehler
	 * @param result
	 * @param sumCounter
	 */
	SummationResult(long double ergebnis, int summenZaehler);
	long double getResult ();
	int getSumZaehler ();
};

} /* namespace std */

#endif /* SUMMATIONRESULT_H_ */
