/* 
 * File:   LehmerKongruenzZufallsgenerator.h
 * Author: fredde
 *
 * Created on 25. Oktober 2015, 15:08
 */

#ifndef LEHMERKONGRUENZZUFALLSGENERATOR_H
#define	LEHMERKONGRUENZZUFALLSGENERATOR_H

#include "AbstractZufallsgenerator.h"
#include "math.h"

class LehmerKongruenzZufallsgenerator : public AbstractZufallsgenerator
{
public:

    LehmerKongruenzZufallsgenerator() : AbstractZufallsgenerator()
    {
        //Defaultswerte setzen
        this->a = 16333.00;
        this->b = 25887.00;
        this->x = 0.00;
        this->m = 32768.00; // 2^15
    }

    double rand()
    {
        //Ich benutze hier fmod, weil ich waehrend des entwickeln immer den Compilerfehler
        // error: invalid operands to binary expression ('double' and 'double') bekommen habe
        //@see http://stackoverflow.com/questions/3902399/error-invalid-operands-to-binary-have-double-and-double
        this->x = fmod((this->a * this->x + this->b), this->m);

        //this->x = (this->a * this->x + this->b) % this->m;

        return x;
    }

    virtual ~LehmerKongruenzZufallsgenerator()
    {

    }

private:

    double a, b, m, x;

};

#endif	/* LEHMERKONGRUENZZUFALLSGENERATOR_H */

