//
// Created by Private on 27.02.16.
//

#ifndef BILDBEARBEITUNG_PGMBILD_H
#define BILDBEARBEITUNG_PGMBILD_H

#include "Defines.h"

struct PGMBild {

    char magic[2];
    int nx;
    int ny;
    int graumax;
    string filetype = "P2";
    Pixel **bild;
};


#endif //BILDBEARBEITUNG_PGMBILD_H
