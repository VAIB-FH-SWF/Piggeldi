/* 
 * File:   DefaultZufallsgenerator.h
 * Author: fredde
 *
 * Created on 25. Oktober 2015, 13:59
 */

#ifndef DEFAULTZUFALLSGENERATOR_H
#define	DEFAULTZUFALLSGENERATOR_H

#include "AbstractZufallsgenerator.h"
#include "cstdlib"

class DefaultZufallsgenerator : public AbstractZufallsgenerator
{
public:

    DefaultZufallsgenerator() : AbstractZufallsgenerator()
    {
    }

    double rand()
    {
        return std::rand();
    }

    virtual ~DefaultZufallsgenerator()
    {

    }

private:

};

#endif	/* DEFAULTZUFALLSGENERATOR_H */

