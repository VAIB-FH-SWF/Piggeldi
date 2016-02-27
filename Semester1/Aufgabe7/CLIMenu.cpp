/* 
 * File:   CLIMenu.cpp
 * Author: fredde
 * 
 * Created on 1. November 2015, 19:27
 */

#include "CLIMenu.h"
#include <iostream>
#include <iomanip>
#include "PGMBild.h"

bool hasEnding(std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

CLIMenu::CLIMenu() {
}

void CLIMenu::start() {

    //Einlesen des Bildnamens
    std::cout << "Willkommen bei der Photoshop-Alternative! Sogar OpenSource ;)" << std::endl;

    std::string bildname = "";
    do {
        std::cout << "Bildname eingeben:" << std::endl;
        bildname = this->leseText();

    } while (!hasEnding(bildname.c_str(), ".pgm"));

    try {

        PGMBild bild = PGMBild(bildname);

        std::cout << "Menü Start: \n g Glättung \n i Invertierung \n k Kantenbildung \n s Schärfung \n c Kopieren \n e Ende \n" << std::endl;
        std::string menuEingabe = "";
        while (true) {
            
            std::cout << "Auswahl :" << std::endl;
            
            menuEingabe = this->leseText();

            if (menuEingabe.size() == 1) {

                switch ((char) menuEingabe[0]) {
                    case 'i':
                        bild.invert(std::string("invert") + std::string(bildname));
                        continue;
                    case 'g':
                        bild.antiAliasing(std::string("glatt") + std::string(bildname));
                        continue;
                    case 'k':
                        bild.edgeDetection(std::string("kante") + std::string(bildname));
                        continue;
                    case 's':
                        bild.sharpening(std::string("scharf") + std::string(bildname));
                        continue;
                    case 'c':
                        bild.copy(std::string("kopie") + std::string(bildname));
                        continue;
                    case 'e':
                        std::cout << "Programm Ende" << std::endl;
                        return;
                    default:
                        std::cout << "Ungütlige Eingabe" << std::endl;
                        continue;
                }

            } else {
                std::cout << "Ungültige Eingabe" << std::endl;
            }
        } 

        return;

    } catch (const char* msg) {
        std::cout << msg << std::endl;
        std::cout << "Programmende" << std::endl;
        return;
    }
}

