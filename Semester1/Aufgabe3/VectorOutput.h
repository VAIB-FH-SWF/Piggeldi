/* 
 * File:   CLIOutput.h
 * Author: fredde
 *
 * Created on 25. Oktober 2015, 10:26
 */

#ifndef CLIOUTPUT_H
#define	CLIOUTPUT_H

#include "Defines.h"

class Vectoroutput
{
public:
    Vectoroutput();

    /**
     * Gibt einen Vector aus. 
     * @param der auszugebende Vector
     * @param spaltenAnzahl
     */
    static void printVector(doubleVector& thevector, int spaltenAnzahl);

private:

};

#endif	/* CLIOUTPUT_H */

