/* 
 * File:   main.cpp
 * Author: fredde
 *
 * Created on 6. November 2015, 09:47
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

/**
 * Berechnet die Quersumme der Zahl
 */
int quersumme(int zahl)
{
    int summe = 0;
    while (zahl > 0)
    {
        summe += zahl % 10;
        zahl /= 10;
    }
    return (summe);
}

/**
 * Berechnet die Pruefsumme der Zahl indem abwechselnd jede Ziffer mit *1/*2 gewichtet wird und 
 * daraus dann die Quersumme gebildet wird
 * @param zu pruefende Zahl
 * @return die Pruefsumme
 */
int berechnePruefsumme (string zahl)
{
   int pruefSumme = 0;
   for (unsigned int i = 0; i < zahl.length(); i++)
   {
       int zuGewichteneZahl = 0;
       zuGewichteneZahl = zahl[i];
       if (i % 2 != 0)
       {
           zuGewichteneZahl*= 2;
       }   
      pruefSumme += quersumme(zuGewichteneZahl);
   }
   return pruefSumme;
}

/**
 * Prueft die Kreditkartenummer
 */
bool luhn_check(string number)
{
    //Die Zahl muss glatt durch 10 Teilbar sein
    return (berechnePruefsumme(number) % 10 == 0);
}

// Haupteinstiegspunkt des Programms
int main()
{
    cout << boolalpha; //ermöglicht die Ausgabe von true/false
    cout << "Pruefe Kreditkartennummern:" << endl;
    
    cout << "       446667651: " << luhn_check("446667651") << endl;
    cout << "     49927398716: " << luhn_check("49927398716") << endl;
    cout << "     49927398717: " << luhn_check("49927398717") << endl;
    cout << "1234567812345678: " << luhn_check("1234567812345678") << endl;
    cout << "1234567812345670: " << luhn_check("1234567812345670") << endl;
}