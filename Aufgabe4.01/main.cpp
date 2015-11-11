/* 
 * File:   main.cpp
 * Author: fredde
 *
 * Created on 26. Oktober 2015, 16:48
 */

#include <iomanip>   
#include <iostream>  

using namespace std;

/*
 Enumeration welche die 3 Zustaende definiert
 */
enum ZUSTAND {
    ZIFFER, LEER, BUCHSTABE
};

int main ( )
{
   int maxstring = 256;                      // Puffergroesse
   char text[maxstring];                     // Eingabepuffer
   char c;                                   // Hilfsvariable
   int textIterator, summeBuchstaben, summeZahlen = 0;       // textIterator,Buchstabezaehler

   cout << "Geben Sie eine Textzeile ein: ";

   while ((c = cin.get()) != '\n')
   {                                          // Einzelzeichen lesen
      text[textIterator] = c;                 //  und im Feld ablegen
      textIterator = textIterator + 1;        // Schleifenzaehler erhoehen
   }
   text[textIterator] = '\0';                 // Zeichenkette abschliessen

   cout << "Der eingegebene Text lautet: '" << text << "'\n";

   for (textIterator = 0; text[textIterator] != '\0'; textIterator += 1)
   {
      if (isalpha(text[textIterator]))
         summeBuchstaben = summeBuchstaben + 1;
      if (isdigit(text[textIterator]))
         summeZahlen = summeZahlen + 1;
   }
   cout << setw(6) << summeBuchstaben << " Buchstaben\n";
   cout << setw(6) << summeZahlen << " Ziffern\n";

   return (0);
}