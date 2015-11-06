/* 
 * File:   main.cpp
 * Author: fredde (powered hoelshare)
 *
 * Created on 26. Oktober 2015, 16:48
 */

#include <iostream>
#include <cmath>
#include <string>

using namespace std;
/**
 * Schreibt ein Wort A der Laenge n in den Ausgabestream
 * @param a das Wort
 * @param n doe laenge des Wortes
 */
void ausgabeFeld(char a[], unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

/**
 * Wendet ein Wort a in sich 
 * @param a das Wort
 * @param n die laenge des Wortes
 */
void feld_wenden(char a[], unsigned int n) {
    char zwischenspeicher;

    for (unsigned int i = 0; i < n / 2; i++) {
        zwischenspeicher = a[i];
        a[i] = a[n - i - 1]; // -1 da im letzten Feld \0 steht
        a[n - i - 1] = zwischenspeicher;
    }
}

/**
 * Verschiebt die Buchstaben des Wort a um shift Plaetze nach links 
 * @param a das Wort
 * @param n die Laenge des Wortes
 * @param shift Anzahl der zuverschiebenden Plaetze
 */
void feld_links_rotieren(char a[], unsigned int n, unsigned int shift) {
    feld_wenden(a, shift);
    feld_wenden(a, n);
    feld_wenden(a, n - shift);
}

/**
 * Verschiebt die Buchstaben des Wort a um shift Plaetze nach rechts 
 * @param a das Wort
 * @param n die Laenge des Wortes
 * @param shift Anzahl der zuverschiebenden Plaetze
 */
void feld_rechts_rotieren(char a[], unsigned int n, unsigned int shift) {
    feld_wenden(a, n - shift);
    feld_wenden(a, n);
    feld_wenden(a, shift);
}

int main() {
    const int feldGroesse = 26;
    //char feld[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    //                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' }; // das Alphabet

    char feld[] = {'B', 'I', 'E', 'R', 'E', 'T', 'R', 'I', 'K', 'E', 'N', 'I', 'S',
                   'T', 'G', 'E', 'S', 'U', 'N', 'D', 'T', 'R', 'I', 'N', 'K', 'T'};


    cout << "Originalfeld:                                               ";
    ausgabeFeld(feld, feldGroesse);
    feld_wenden(feld, feldGroesse);
    cout << "Komplett gewendetes Feld:                                   ";
    ausgabeFeld(feld, feldGroesse);
    feld_wenden(feld, feldGroesse);
    cout << "Zurück gewendet:                                            ";
    ausgabeFeld(feld, feldGroesse);
    feld_links_rotieren(feld, feldGroesse, 5);
    cout << "Verschiebung eines Feldinhalts um 5 Positionen nach Links:  ";
    ausgabeFeld(feld, feldGroesse);
    feld_rechts_rotieren(feld, feldGroesse, 5);
    cout << "Verschiebung eines Feldinhalts um 5 Positionen nach Rechts: ";
    ausgabeFeld(feld, feldGroesse);

    return (0);
}

