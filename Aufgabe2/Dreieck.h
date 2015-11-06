/* 
 * File:   Dreieck.h
 * Author: fredde
 *
 * Created on 10. Oktober 2015, 20:11
 */

#ifndef DREIECK_H
#define	DREIECK_H

#include <string>
#include <sstream>

class Dreieck
{
public:

    /**
     * Defaultkonstruktor des Dreiecks
     */
    Dreieck() : Dreieck(0, 0, 0)
    {
    };
    /**
     * Dreieckserstellung mit den 3 Seitenlaengen des Dreieckes
     * @param seiteA
     * @param seiteB
     * @param seiteC
     */
    Dreieck(double seiteA, double seiteB, double seiteC);

    double GetSeiteA() const
    {
        return seiteA;
    }

    double GetSeiteB() const
    {
        return seiteB;
    }

    double GetSeiteC() const
    {
        return seiteC;
    }

    std::string print() const
    {
        std::stringstream ss;

        ss << "A=" << seiteA << "/B=" << seiteB << "/C=" << seiteC;

        return ss.str();
    }


    virtual ~Dreieck();
private:

    double seiteA, seiteB, seiteC;

};

#endif	/* DREIECK_H */

