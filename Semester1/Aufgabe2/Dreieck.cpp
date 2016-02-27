/* 
 * File:   Dreieck.cpp
 * Author: fredde
 * 
 * Created on 10. Oktober 2015, 20:11
 * Compiler g++
 */

#include "Dreieck.h"

Dreieck::Dreieck(double seiteA, double seiteB, double seiteC) {
    //Alle drei Seiten muessen groesser als 0 sein
    if ((seiteA > 0.0) && (seiteB > 0.0) && (seiteC > 0.0)) {
        this->seiteA = seiteA;
        this->seiteB = seiteB;
        this->seiteC = seiteC;
    } else {
        this->seiteA = 0;
        this->seiteB = 0;
        this->seiteC = 0;
    }
}

Dreieck::~Dreieck() {
}

