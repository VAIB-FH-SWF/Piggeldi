/* 
 * File:   PGMBild.cpp
 * Author: fredde
 * 
 * Created on 31. Oktober 2015, 15:40
 */

#include "PGMBild.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

PGMBild::PGMBild(std::string name) {

    //Liest das Bild in das Koordinatenarray ein
    if (this->parseBild(name, this->pixelFelder)) {
        this->bildName = name;
    } else {
        throw "Bild konnte nicht erzeugt werden";
    }

}

bool PGMBild::copy(std::string copyName) {

    return this->printBild(this->pixelFelder, copyName);
}

bool PGMBild::printBild(pixel pixelInformationen[N][N], std::string dateiname) {

    std::ofstream outputStream;
    bool status = false;

    outputStream.open(dateiname.c_str());

    if (outputStream) {
        std::cout << "Erzeuge " << dateiname << " ..." << std::endl;
        status = true;
        //Die Kopfinformationen zuerst schreiben
        outputStream << this->bildCodierung << std::endl; //Codierung
        outputStream << this->bildBreite << " " << this->bildHoehe << std::endl; //Die Aufloesung
        outputStream << this->maximalerGrauwert << std::endl; //Der maximale Grauwert

        for (int zeile = 0; zeile < this->anzahlPixelZeilen; ++zeile) {

            for (int spalte = 0; spalte < this->grauWerteProZeile; ++spalte) {

                outputStream << " " << (int) pixelInformationen[zeile][spalte];
                //std::cout << zeile << "/" << spalte << "=" << this->pixelFelder[zeile][spalte] << std::endl;
            }
            outputStream << std::endl;
        }
    } else {
        std::cout << "Datei " << dateiname << " konnte nicht geoffent werden" << std::endl;
    }

    outputStream.close();
    return status;

}

bool PGMBild::parseBild(std::string name, pixel(&pixelInformation)[N][N]) {

    std::ifstream inputStream(name);

    bool status = true;

    //Pruefen ob das Bild erfolgreich eingelesen wurde
    if (inputStream) {

        std::string zeile;
        int zeilenZaehler = 0;
        int pixelZeilenZaehler = 0;
        //Pro Zeile
        while (getline(inputStream, zeile)) {

            //Die ersten drei zahlen muessen auf codierung/maximalergrauwert/aufloesung geprueft werden
            if (!this->validateBildZeile(zeile, zeilenZaehler)) {

                return false;
            }

            // Ab zeile 3 gehts mit den pixel informationen los
            if (zeilenZaehler >= 3) {
                // Die Integerwerte aus dem String holen
                IntegerVector pixelVector = this->integersFromString(zeile);

                for (IntegerVector::size_type i = 0; i < pixelVector.size(); i++) {

                    pixelInformation[pixelZeilenZaehler][i] = pixelVector[i];
                }
                pixelZeilenZaehler++;
            }
            zeilenZaehler++;
        }
        //Bild wurde erfolgreich ins array eingelesen
        this->anzahlPixelZeilen = pixelZeilenZaehler + 1; // +1 da der Zeilenzaehler bei 0 beginnt
    } else {
        status = false;
        std::cout << "Bild konnte nicht eingelesen werden" << std::endl;
    }

    inputStream.close();

    return status;
}

bool PGMBild::validateBildZeile(std::string inhalt, int zeile) {

    bool status = true;
    std::string fehlermeldung = "";
    //Die Codierungszeile
    if (zeile == 0) {

        std::cout << "Die Codierung ist " << inhalt << std::endl;
        status = (inhalt.compare("P2") == 0);
        fehlermeldung = "Die Codierung passt nicht";
        this->bildCodierung = inhalt;

    }//Bildbreite/Hoehe in Pixel
    else if (zeile == 1) {

        IntegerVector intVector = this->integersFromString(inhalt);
        this->bildBreite = intVector[0];
        this->bildHoehe = intVector[1];
        status = (this->bildBreite < this->N && this->bildHoehe < this->N);
        std::cout << "Die Dimension ist " << this->bildBreite << "/" << this->bildHoehe << std::endl;
        fehlermeldung = "Das Bild ist zu gross";

    }//Maximaler grauwert
    else if (zeile == 2) {

        this->maximalerGrauwert = std::stoi(inhalt);
        status = (this->maximalerGrauwert > 0 && this->maximalerGrauwert <= 255);
        std::cout << "Maximalergrauwert ist " << this->maximalerGrauwert << std::endl;
        fehlermeldung = "Der Grauwert ist falsch.";
    }

    if (!status) {

        std::cout << "\nERROR: " << fehlermeldung << std::endl;
    }
    return status;
}

IntegerVector PGMBild::integersFromString(std::string text) {

    IntegerVector zahlenVector;

    bool merkerIsSpace = false;
    std::string numberString;

    //den string ziffer fuer ziffer durchrennen
    for (std::string::size_type i = 0; i < text.size(); ++i) {

        if (isdigit(text[i])) {

            numberString += (text[i]);

        } else if (isspace(text[i])) {

            merkerIsSpace = true;
        }

        if (merkerIsSpace) {
            //String verarbeiten
            if (!numberString.empty()) {

                //std::cout << numberString << std::endl;
                zahlenVector.push_back(std::stoi(numberString));
                numberString.clear();
            }

            merkerIsSpace = false;
        }
    }

    if (!numberString.empty()) {
        //std::cout << numberString << std::endl;
        zahlenVector.push_back(std::stoi(numberString));
    }

    return zahlenVector;
}

bool PGMBild::antiAliasing(std::string pictureName) {

    bool status = true;
    pixel pixelInformation [N][N];

    //Fuer jeden Zeile...
    for (int zeile = 0; zeile < this->anzahlPixelZeilen; ++zeile) {
        //Fuer jede Spalte...
        for (int spalte = 0; spalte < this->grauWerteProZeile; ++spalte) {

            IntegerVector nachbarPixel = this->findePixelNachbarn(this->pixelFelder, zeile, spalte);

            int pixelSumme = 0;
            //Konnten die Nachbarn des Pixel ermittelt werden?
            if (nachbarPixel.size() == 9) {
                for (IntegerVector::size_type i = 0; i < nachbarPixel.size(); i++) {

                    pixelSumme += nachbarPixel[i];
                }
                //Durchschnitt ermitteln
                pixelSumme = pixelSumme / nachbarPixel.size();
            } else {

                pixelSumme = 0;
            }
            pixelInformation[zeile][spalte] = pixelSumme;
        }
    }
    this->printBild(pixelInformation, pictureName);
    return status;
}

bool PGMBild::edgeDetection(std::string pictureName) {

    bool status = true;
    pixel pixelInformation [N][N];

    //Fuer jeden Zeile...
    for (int zeile = 0; zeile < this->anzahlPixelZeilen; ++zeile) {
        //Fuer jede Spalte...
        for (int spalte = 0; spalte < this->grauWerteProZeile; ++spalte) {

            IntegerVector nachbarPixel = this->findePixelNachbarn(this->pixelFelder, zeile, spalte);

            // Handelt es sich nicht um raender
            if (nachbarPixel.size() == 9) {

                int pixelWert = std::abs(
                        (nachbarPixel[1] * -1 +
                        nachbarPixel[3] * -1 +
                        nachbarPixel[4] * 4 +
                        nachbarPixel[5] * -1 +
                        nachbarPixel[7] * -1) / 9);

                pixelInformation[zeile][spalte] = pixelWert;

            } else {
                pixelInformation[zeile][spalte] = 0;
            }

        }
    }

    this->printBild(pixelInformation, pictureName);
    return status;
}

bool PGMBild::invert(std::string pictureName) {

    bool status = true;
    pixel pixelInformation [N][N];

    for (int zeile = 0; zeile < this->anzahlPixelZeilen; ++zeile) {

        for (int spalte = 0; spalte < this->grauWerteProZeile; ++spalte) {

            int grauWert = (int) this->pixelFelder[zeile][spalte];

            pixelInformation[zeile][spalte] = this->maximalerGrauwert - grauWert;
        }
    }

    this->printBild(pixelInformation, pictureName);

    return status;
}

bool PGMBild::sharpening(std::string pictureName) {

    bool status = true;
    pixel pixelInformation [N][N];

    //Fuer jeden Zeile...
    for (int zeile = 0; zeile < this->anzahlPixelZeilen; ++zeile) {
        //Fuer jede Spalte...
        for (int spalte = 0; spalte < this->grauWerteProZeile; ++spalte) {

            IntegerVector nachbarPixel = this->findePixelNachbarn(this->pixelFelder, zeile, spalte);

            // Handelt es sich nicht um die bilder raender
            if (nachbarPixel.size() == 9) {

                int pixelWert =
                        nachbarPixel[0] * -1 +
                        nachbarPixel[1] * -1 +
                        nachbarPixel[2] * -1 +
                        nachbarPixel[3] * -1 +
                        nachbarPixel[4] * 9 +
                        nachbarPixel[5] * -1 +
                        nachbarPixel[6] * -1 +
                        nachbarPixel[7] * -1 +
                        nachbarPixel[8] * -1;

                // falls der maximale grauwert uberstiegen wurde
                if (pixelWert > this->maximalerGrauwert) {
                    pixelWert = this->maximalerGrauwert;
                }                    // falls der pixelwert negativ geworden ist
                else if (pixelWert < 0) {
                    pixelWert = 0;
                }

                pixelInformation[zeile][spalte] = pixelWert;

            } else {
                pixelInformation[zeile][spalte] = 0;
            }
        }
    }
    this->printBild(pixelInformation, pictureName);

    return status;
}

IntegerVector PGMBild::findePixelNachbarn(pixel pixelInformationen[N][N], int zeile, int spalte) {

    IntegerVector pixelNachbarn;

    //Die Raender abfangen
    if (spalte == 0 || spalte == this->grauWerteProZeile - 1 || zeile == 0 || zeile == this->anzahlPixelZeilen - 1) {

        return pixelNachbarn;
    }

    for (int zaehlerZeiler = zeile - 1; zaehlerZeiler <= zeile + 1; zaehlerZeiler++) {

        for (int zaehlerSpalte = spalte - 1; zaehlerSpalte <= spalte + 1; zaehlerSpalte++) {

            pixelNachbarn.push_back(pixelInformationen[zaehlerZeiler][zaehlerSpalte]);
        }
    }

    return pixelNachbarn;
}

bool PGMBild::fill(std::string pictureName, pixel oldVal, pixel newVal, int inz, int ins) {
    
    
    
    if (this->pixelFelder[inz][ins] == oldVal) {
        
        this->pixelFelder[inz][ins] = newVal;
    }
    return 
    
}




