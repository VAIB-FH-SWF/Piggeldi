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

	/**
	 * Liesst ein Bild ein
	 * @param bild Pointer auf das zu erzeugende Bild
	 * @param ifs_file_name Pfad mit Dateinamen zu dem Bild
	 */
	void bild_lesen(PGMBild *bild, string ifs_file_name);

	/**
	 * Schreibt das das Bild in die datei
	 * @param bild bild
	 * @param ofs_file_name Name der Datei
	 */
	void bild_schreiben(PGMBild *bild, string ofs_file_name);

	/**
	 * Loescht eine Pixelmatrix
	 * @param m zu loeschende matrix
	 */
	void delete_pixel_matrix(Pixel **m);

	/**
	 * Erstellt eine neue Pixelmatrix
	 * @param rows zeilenzahl
	 * @param columns spaltenzahl
	 * @return erzeugte matrix
	 */
	Pixel ** new_pixel_matrix(size_t rows, size_t columns);
	/**
	 * Ubernimmt die Pixel aus Bild1 und erzeugt daraus eine neue bild 2 wobei
	 * das bild2 geglaettet wird
	 * @param bild1 quellbild
	 * @param bild2 zielbild
	 */
	void glaetten(PGMBild *bild1, PGMBild *bild2);

	/**
	 * Ubernimmt die Pixel aus Bild1 und erzeugt daraus eine neue bild 2 wobei
	 * das bild2 invertiert wird
	 * @param bild1 quellbild
	 * @param bild2 zielbild
	 */
	void invertieren(PGMBild *bild1, PGMBild *bild2);

	/**
	 * Ubernimmt die Pixel aus Bild1 und erzeugt daraus eine neue bild 2 wobei
	 * bei bild 2 die kanten hervorgehoben sind
	 * @param bild1 quellbild
	 * @param bild2 zielbild
	 */
	void kantenbildung(PGMBild *bild1, PGMBild *bild2);
    /**
     * Kopiert die Bildinformationen aus dem Bildkopf in bild 2
     * @param bild1 quellebild
     * @param bild2 zielbild
     */
	void kopiere_bildkopf(PGMBild *bild1, PGMBild *bild2);

private:
    /**
     * Prueft ob es sich beim dem Bild um ein pgm-Bild handlet
     * @param bild zupruefendes bild
     * @return true/istPgmBild/false=others
     */
	bool istPGMBild(PGMBild *bild);
    /**
     * Parset die Bildinformationen aus einem Filestream in das bild
     * @param fileStream filestream auf ein bild
     * @param bild
     */
	void parse_bild_informationen(ifstream &fileStream, PGMBild *bild);
};

#endif //BILDBEARBEITUNG_PGMBILDREPO_H
