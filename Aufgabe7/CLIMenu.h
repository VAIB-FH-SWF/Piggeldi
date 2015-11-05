/* 
 * File:   CLIMenu.h
 * Author: fredde
 *
 * Created on 1. November 2015, 19:27
 */

#ifndef CLIMENU_H
#define	CLIMENU_H

#include "CLIBasic.h"

class CLIMenu : public CLIBasic
{
public:
    CLIMenu();

    /**
     * Startet die Menu Verarbeitung.
     */
    void start();
};

#endif	/* CLIMENU_H */

