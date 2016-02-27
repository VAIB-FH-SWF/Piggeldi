/* 
 * File:   CLIInputDreieck.h
 * Author: fredde
 *
 * Created on 11. Oktober 2015, 08:39
 */

#ifndef CLIINPUTDREIECK_H
#define	CLIINPUTDREIECK_H

#include "CLIInput.h"
#include <string>

class CLIInputDreieck : public CLIInput
{
public:
    CLIInputDreieck();

    /**
     * Liest die Dreiecksflaechen ueber das CLI ein 
     * und gibt ein das eingelesene Dreieck wieder zurueck
     * @return Dreieck
     */
    Dreieck leseDreieckFlaechen();

private:

    /**
     * Liest ein Dreieckseite ein 
     * @param Die Bezeichnung der Seite (A/B/C)
     * @return Die eingelesene Dreiecksflaeche
     */
    double leseDreieckSeite(std::string seitenBezeichnung);

};

#endif	/* CLIINPUTDREIECK_H */

