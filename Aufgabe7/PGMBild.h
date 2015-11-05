/* 
 * File:   PGMBild.h
 * Author: fredde
 *
 * Created on 31. Oktober 2015, 15:40
 */

#ifndef PGMBILD_H
#define	PGMBILD_H

#include <string>
#include <vector>

typedef unsigned char pixel;

typedef std::vector<int> IntegerVector;

class PGMBild
{
public:

    PGMBild(std::string name);

    /**
     * Kopiert das Bild
     * @param copyName der Name der Copy
     * @return true=success/false=other
     */
    bool copy(std::string copyName);

    /**
     * Invertiert das Bild
     * @param Name der Ausgabedatei
     * @return true=success/false=other
     */
    bool invert(std::string pictureName);

    /**
     * Glaettet das Bild
     * @param pictureName Name der Ausgabedatei
     * @return true=success/false=other
     */
    bool antiAliasing(std::string pictureName);

    /**
     * Kantenerkennung
     * @param pictureName Name der Ausgabedatei
     * @return true=success/false=other
     */
    bool edgeDetection(std::string pictureName);

    /**
     * Schaerft das Bild
     * @param pictureName Name der Ausgabedatei
     * @return true=success/false=other
     */
    bool sharpening(std::string pictureName);

private:
    static const int N = 1000; //maximale Bildgroesse
    static const int grauWerteProZeile = 512; // Grauwerte pro Zeile
    pixel pixelFelder[N][N]; //Beinhaltet die Bildinformationen
    int anzahlPixelZeilen, bildBreite, bildHoehe, maximalerGrauwert; //Merker fuer die Bildmetadaten 
    std::string bildCodierung, bildName;

    /**
     * Parst das Bild in ein Bildarray
     */
    bool parseBild(std::string name, pixel(&pixelInformation)[N][N]);

    /**
     * Uberprueft ob die Zeile des pgm-Bild-Valid ist
     * @param inhalt
     * @param zeile
     * @return true=success/else others
     */
    bool validateBildZeile(std::string inhalt, int zeile);

    /**
     * Ermittelt alle Integerwerte im String und liefert diese im Vector zurueck
     * Erste Eintrag ist auch die erste gefundene Zahl
     * @param zu ueberpruefenden string
     * @return vector mit integer-value
     */
    IntegerVector integersFromString(std::string text);

    /**
     * Schreibt ein Bild auf Basis der Pixelinformationen ins Filesystem
     * @param pixelInformationen array mit pixel
     * @param dateiname Name der Ausgabedatei
     * @return true=success/false=other
     */
    bool printBild(pixel pixelInformationen[N][N], std::string dateiname);

    /**
     * Findet die Nachbarn zu einem Pixel
     * Die Pixel werden in folgender Reihenfolge zurueck geliefert:
     * 1 2 3
     * 4 5 6
     * 7 8 9
     * @param pixelInformationen
     * @param x
     * @param y
     * @return liste von integerwerten der pixel
     */
    IntegerVector findePixelNachbarn(pixel pixelInformationen[N][N], int zeile, int spalte);

};

#endif	/* PGMBILD_H */

