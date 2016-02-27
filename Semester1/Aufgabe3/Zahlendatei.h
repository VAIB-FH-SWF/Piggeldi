/* 
 * File:   Zahlendatei.h
 * Author: fredde
 *
 * Created on 25. Oktober 2015, 13:29
 */

#ifndef ZAHLENDATEI_H
#define	ZAHLENDATEI_H

#include <string>
#include "Defines.h"

class Zahlendatei
{
public:

    Zahlendatei(std::string& dateiname);

    doubleVector& leseDatei();
private:

    doubleVector zahlenListe;
    std::string dateiname;

};

#endif	/* ZAHLENDATEI_H */

