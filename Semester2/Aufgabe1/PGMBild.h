//
// Created by Private on 27.02.16.
//

#ifndef BILDBEARBEITUNG_PGMBILD_H
#define BILDBEARBEITUNG_PGMBILD_H

#include "Defines.h"
/**
 * Definiert ein Bild
 */
struct PGMBild {

	/**
	 * breite des bildes
	 */
    int nx;
    /**
     * hoehe des bildes
     */
    int ny;
    /**
     * maximaler grauwert des bildes
     */
    int graumax;
    /**
     * bildtyp
     */
    string filetype = "P2";
    /**
     * pixelinformationen
     */
    Pixel **bild;
};


#endif //BILDBEARBEITUNG_PGMBILD_H
