/* 
 * File:   CLIOutput.cpp
 * Author: fredde
 * 
 * Created on 25. Oktober 2015, 10:26
 * Compiler g++
 */

#include "VectorOutput.h"
#include <iostream>
#include <iomanip>

Vectoroutput::Vectoroutput() {
}

void Vectoroutput::printVector(doubleVector& thevector, int spaltenAnzahl) {
    int spaltenZaehler = 0;
    for (doubleVector::size_type i  = 0; i < thevector.size(); i++) {
        spaltenZaehler++;
        std::cout << std::fixed << std::setprecision(0) << thevector[i] << "\t";

        if (spaltenZaehler == spaltenAnzahl) {
            std::cout << std::endl;
            spaltenZaehler = 0;
        }
    }
}