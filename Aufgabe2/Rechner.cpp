/* 
 * File:   Rechner.cpp
 * Author: fredde
 * 
 * Created on 10. Oktober 2015, 19:59
 * Compiler g++
 */

#include "Rechner.h"
#include <cmath>

using namespace std;

float Rechner::multiDividiereMitGleitkommaZahl(float riesigeGleitkommaZahl) {
    float faktor = 0.1693f;

    int anzahlRechenoperation = 10; // Definiert die Anzahl der auszufuehrenden Rechenoperationen

    for (int i = 1; i <= 10; i++) {
        riesigeGleitkommaZahl *= faktor;
    }


    for (int i = 1; i <= anzahlRechenoperation; i++) {
        riesigeGleitkommaZahl /= faktor;
    }
    
    return riesigeGleitkommaZahl;
}

double Rechner::ermittelDreiecksflaecheMitHeron1(Dreieck& dreieck) {
    
    double s = (0.5) * (dreieck.GetSeiteA() + dreieck.GetSeiteB() + dreieck.GetSeiteC());

    double wurzelAusdruck = s * (s - dreieck.GetSeiteA()) * (s - dreieck.GetSeiteB()) * (s - dreieck.GetSeiteC());

    if (wurzelAusdruck <= 0) {
        return wurzelAusdruck;
    }
    else {
        return sqrt(wurzelAusdruck);
    }
    
}

double Rechner::ermittelDreiecksflaecheMitHeron2(Dreieck& dreieck) {
    
    double a, b, c;
    
    a = dreieck.GetSeiteA();
    b = dreieck.GetSeiteB();
    c = dreieck.GetSeiteC();
    
    double wurzelAusdruck = (a + b + c) * (a + b - c) * (b + c - a) * (c + a - b);

    if (wurzelAusdruck <= 0) {
        return wurzelAusdruck;
    }
    else {
        return 0.25 * sqrt(wurzelAusdruck);
    }
}

