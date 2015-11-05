/* 
 * File:   AbstractZufallsgenerator.h
 * Author: fredde
 *
 * Created on 25. Oktober 2015, 13:54
 */

#ifndef ABSTRACTZUFALLSGENERATOR_H
#define	ABSTRACTZUFALLSGENERATOR_H

/**
 * Die Abstractklasse fur den Zufallsgenerator.
 */
class AbstractZufallsgenerator
{
public:

    /**
     * Erzeugt den Zufallsgenerator ohne Zahlengrenze
     */
    AbstractZufallsgenerator()
    {
    };

    /**
     * Ermittelt eine zufaellige Zahl
     * @return 
     */
    virtual double rand() = 0;

    virtual ~AbstractZufallsgenerator()
    {

    }

};

#endif	/* ABSTRACTZUFALLSGENERATOR_H */

