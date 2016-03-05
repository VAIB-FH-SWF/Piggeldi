//
// Created by Private on 27.02.16.
//

#include <iomanip>
#include <cmath>
#include "PGMBildRepo.h"


void PGMBildRepo::bild_lesen(PGMBild *bild, string ifs_file_name) {

    ifstream inputStream(ifs_file_name);

    if (!inputStream){

        cout << "Datei" << ifs_file_name << " konnte nicht eingelesen werden";
        inputStream.close();
        return;
    }

    this->parse_bild_informationen(inputStream,bild);

    if(!this->istPGMBild(bild)) {

        cout << "Es handelt sich nicht um ein PGMBild";
        inputStream.close();
        return;
    }

    for (int row = 0; row < bild->ny; row++){

        for (int column = 0; column < bild->nx; column++){

            double pixelWert = 0;

            inputStream >> pixelWert;

            bild->bild[row][column] = (int)pixelWert;
        }
    }

    inputStream.close();
}

void PGMBildRepo::bild_schreiben(PGMBild *bild, string ofs_file_name) {

    ofstream dateistream;
    int ausgaben = 0;
    dateistream.open(ofs_file_name.c_str());

    if (!dateistream){

        cout << "Datei konnte nicht erzeugt werden" << endl;
        dateistream.close();
        return;
    }

    dateistream << bild->filetype << endl;
    dateistream << bild->nx << " ";
    dateistream << bild->ny << endl;
    dateistream << bild->graumax << endl;
    dateistream << right;

    for(int row = 0; row < bild->ny; row++)
    {
        for(int col = 0; col < bild->nx; col++)
        {
            ausgaben++;
            dateistream << " " << setw(3) << (int) (bild->bild[row][col]);
            if(ausgaben % 18 == 0)    // Eine Zeile darf maximal 75 Zeichen beeinhalten
            {
                dateistream << endl;
            }
        }
    }
    dateistream.flush();
    dateistream.close();

}

void PGMBildRepo::delete_pixel_matrix(Pixel **m) {

    delete[] *m;
    delete[] m;
}

Pixel **PGMBildRepo::new_pixel_matrix(size_t rows, size_t columns) {

    size_t i;
    Pixel **m;

    m = new Pixel*[rows];
    *m = new Pixel[rows*columns];

    for(i=1; i<rows;i+=1){

        m[i] = m[i-1] + columns;
    }
    return m;
}

void PGMBildRepo::glaetten(PGMBild *bild1, PGMBild *bild2) {

    this->kopiere_bildkopf(bild1,bild2);
    int sum, anz = 0;
    for (int row = 0; row < bild1->ny ; row++)
    {
        for (int col = 0; col < bild1->nx; col++)
        {
            sum = anz = 0;

            for (int tRow = max(0, row - 1); tRow < min(bild1->ny, row + 1); tRow++)
            {

                for (int tCol = max(0, col - 1); tCol < min(bild1->nx, col + 1);
                     tCol++)
                {
                    sum += bild1->bild[tRow][tCol];
                    anz++;
                }
            }
            // Den mittelwert berechnen und das Ergebnis runden
            bild2->bild[row][col] = round(((double) sum) / anz);
        }
    }
}

void PGMBildRepo::invertieren(PGMBild *bild1, PGMBild *bild2) {

    this->kopiere_bildkopf(bild1,bild2);
    for(int row = 0; row < bild1->ny; row++)
    {
        for(int col = 0; col < bild1->nx; col++)
        {
            bild2->bild[row][col] = bild1->graumax - bild1->bild[row][col];
        }
    }
}

void PGMBildRepo::kantenbildung(PGMBild *bild1, PGMBild *bild2) {

    int sum, anz, anzDirekterNachbar;
    this->kopiere_bildkopf(bild1,bild2);
    for (int row = 0; row < bild1->ny; row++)
    {
        for (int col = 0; col < bild1->nx; col++)
        {
            // Prueft ob das Feld im Bereich des Bildes liegt und summiert im Erfolgsfall
            // Erhoet dann ebenfalls die Anzahl
            sum = anz = anzDirekterNachbar = 0;
            for (int tRow = max(0, row - 1); tRow < min(bild1->ny, row + 1); tRow++)
            {
                // Von Spalte - 1 bis Spalte + 1
                // falls diese im Bereich des Bildes sind
                for (int tCol = max(0, col - 1); tCol < min(bild1->nx, col + 1);
                     tCol++)
                {
                    // Summe und Anzahl erhoehen
                    // Wenn der Pixel in der gleichen Spalte oder Reihe ist,
                    // und nicht gleich der Pixel in der Mitte ist
                    if ((tRow == row || tCol == col)
                        && !(tRow == row && tCol == col))
                    {
                        sum -= bild1->bild[tRow][tCol];
                        anzDirekterNachbar++;
                    }
                    anz++;
                }
            }
            // Der mittlere Pixel wird mit der Anzahl der Umgebungspixel Multipliziert
            // An dieser Stelle bin ich davon ausgegangen, das dieser mit der Anzahl 5
            // Gewichtet wird
            sum += (anzDirekterNachbar * bild1->bild[row][col]);

            bild2->bild[row][col] = abs(round(((double) sum) / anz));
        }
    }
}

void PGMBildRepo::kopiere_bildkopf(PGMBild *bild1, PGMBild *bild2) {

    bild2->ny       = bild1->ny;
    bild2->nx       = bild1->nx;
    bild2->graumax  = bild1->graumax;
    bild2->filetype = bild2->filetype;
}

void PGMBildRepo::parse_bild_informationen(ifstream& fileStream, PGMBild *bild) {

    string fileType;

    fileStream >> fileType;
    fileStream >> bild->nx; //Weite
    fileStream >> bild->ny; //Hoehe
    fileStream >> bild->graumax;

    bild->bild = this->new_pixel_matrix(bild->ny,bild->nx);
}

bool PGMBildRepo::istPGMBild(PGMBild *bild) {

    return bild->graumax >= 0 || bild->graumax <= 255 && bild->filetype == "P2";
};
