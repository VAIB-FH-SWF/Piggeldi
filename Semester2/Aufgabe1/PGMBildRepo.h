//
// Created by Private on 27.02.16.
//

#ifndef BILDBEARBEITUNG_PGMBILDREPO_H
#define BILDBEARBEITUNG_PGMBILDREPO_H

#include "Defines.h"
#include "PGMBild.h"
#include <iostream>
#include <fstream>

using namespace std;

class PGMBildRepo {

public:

    void bild_lesen (PGMBild *bild, string ifs_file_name);

    void bild_schreiben(PGMBild *bild, string ofs_file_name);

    void delete_pixel_matrix(Pixel **m);

    Pixel ** new_pixel_matrix (size_t rows, size_t columns);

    void glaetten (PGMBild *bild1, PGMBild *bild2);

    void invertieren(PGMBild *bild1, PGMBild *bild2);

    void kantenbildung(PGMBild *bild1, PGMBild *bild2);

    void kopiere_bildkopf(PGMBild *bild1, PGMBild *bild2);

    void schwellwert (PGMBild *bild1, PGMBild *bild2, Pixel schwellwert);

private:

    bool istPGMBild(PGMBild *bild);

    void parse_bild_informationen(ifstream &fileStream, PGMBild *bild);
};



#endif //BILDBEARBEITUNG_PGMBILDREPO_H
