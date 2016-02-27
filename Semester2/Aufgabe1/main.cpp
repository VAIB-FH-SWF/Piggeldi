#include <iostream>
#include "PGMBildRepo.h"

using namespace std;

int main() {

    PGMBildRepo *repo = new PGMBildRepo();
    PGMBild *bild     = new PGMBild();

    repo->bild_lesen(bild, "/Users/private/Studium/C++/Piggeldi/Semester2/Aufgabe1/dreifach.pgm");

    repo->bild_schreiben(bild,"/Users/private/Studium/C++/Piggeldi/Semester2/Aufgabe1/dreifach2.pgm");

    repo->delete_pixel_matrix(bild->bild);
}