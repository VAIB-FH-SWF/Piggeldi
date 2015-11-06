/* 
 * File:   main.cpp (powered by hoelshare)
 * Author: fredde
 *
 * Created on 6. November 2015, 08:30
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef unsigned int uint;

const uint nmat = 10;

/**
 * Funktionsprototyping
 */
void matrix_diag(int mat[nmat][nmat], uint n, uint diag, int value);
void matrix_dreieck(int mat[nmat][nmat], uint n, uint k, int value);
void matrix_frame(int mat[nmat][nmat], uint n, uint frame, int value);
void matrix_null(int mat[nmat][nmat], uint n);
void matrix_print(int mat[nmat][nmat], uint n);

int main() {
    int mat[nmat][nmat];
    matrix_null(mat, nmat);
    cout << "10x10-Matrix; Nullmatrix:" << endl;
    matrix_print(mat, nmat);

    matrix_frame(mat, nmat, 2, 1);
    cout << endl << "10x10-Matrix; Rahmenstaerke 2:" << endl;
    matrix_print(mat, nmat);

    matrix_diag(mat, nmat, 3, 1);
    cout << endl << "10x10-Matrix; 3 Diagonalen:" << endl;
    matrix_print(mat, nmat);

    matrix_dreieck(mat, nmat, 5, 1);
    cout << endl << "10x10-Matrix; 5 Diagonalreihen links oben:" << endl;
    matrix_print(mat, nmat);
    return (0);
}

void matrix_print(int mat[nmat][nmat], uint n) {
    for (uint zeile = 0; zeile < n; zeile++) {
        for (uint spalte = 0; spalte < n; spalte++) {
            cout << setw(4) << mat[zeile][spalte];
        }
        cout << endl;
    }
}

void matrix_null(int mat[nmat][nmat], uint n) {
    for (uint zeile = 0; zeile < n; zeile++) {
        for (uint spalte = 0; spalte < n; spalte++) {
            mat[zeile][spalte] = 0;
        }
    }
}

void matrix_frame(int mat[nmat][nmat], uint n, uint frame, int value) {
    if (frame > n / 2 + 1) {
        frame = n / 2 + 1;
    }
    matrix_null(mat, n);
    for (uint zeile = 0; zeile < n; zeile++) {
        for (uint spalte = 0; spalte < n; spalte++) {
            if (zeile < frame || n - zeile <= frame || spalte < frame
                    || n - spalte <= frame) {
                mat[zeile][spalte] = value;
            }
        }
    }
}

void matrix_diag(int mat[nmat][nmat], uint n, uint diag, int value) {
    if (diag > n / 2 - 1) {
        diag = n / 2 - 1;
    }

    matrix_null(mat, n);

    for (uint zeile = 0; zeile < n; zeile++) {
        for (uint spalte = 0; spalte < n; spalte++) {
            if (zeile == spalte) {
                int diagBreite = 0;
                for (uint diagZaehler = 0; diagZaehler < diag; diagZaehler++) {
                    //Bei 0 ist es die mittlere Diagonale
                    if (diagZaehler == 0) {
                        mat[zeile][spalte] = value;   
                    }
                    //Sobald eine ungerade Zahl von Diagonalen vorliegt,
                    //wird die Diagonale um Faktor 1 breiter
                    else if (diagZaehler % 2 != 0) {
                        diagBreite ++;
                        mat[zeile + diagBreite][spalte] = value;
                        mat[zeile][spalte + diagBreite] = value;
                    }
                }
            }
        }
    }
}

void matrix_dreieck(int mat[nmat][nmat], uint n, uint k, int value) {
    if (k > n / 2 - 1) {
        k = n / 2 - 1;
    }

    matrix_null(mat, n);
    for (uint zeile = 0; zeile < n; zeile++) {
        for (uint spalte = 0; spalte < n; spalte++) {
            if (zeile + spalte <= k) {
                mat[zeile][spalte] = value;
            }
        }
    }
}


