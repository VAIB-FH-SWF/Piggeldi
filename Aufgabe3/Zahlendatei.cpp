/* 
 * File:   Zahlendatei.cpp
 * Author: fredde
 * 
 * Created on 25. Oktober 2015, 13:29
 */

#include "Zahlendatei.h"
#include <fstream>
#include <iostream>
#include <vector>

Zahlendatei::Zahlendatei(std::string& dateiname) {

    this->dateiname = dateiname;
}

doubleVector& Zahlendatei::leseDatei() {
    std::ifstream dateiStream;

    dateiStream.open(this->dateiname.c_str());

    if (dateiStream) {
        double zeilenWert = 0.0;

        while (dateiStream >> zeilenWert) {
            this->zahlenListe.push_back(zeilenWert);
        }
    } else {
        std::cerr << "\n ERROR: Datei " << dateiname << " konnte nicht gefunden/geoeffnet werden";
    }
    
    std::cout << "Insgesamt " << this->zahlenListe.size() << " Zeilen eingelesen" << std::endl;
    
    return this->zahlenListe;
}
