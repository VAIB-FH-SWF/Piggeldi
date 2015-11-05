/* 
 * File:   main.cpp
 * Author: fredde
 *
 * Created on 27. Oktober 2015, 16:57
 */

#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//Uberprueft ob ein bestimmtes zeichen im array ist.
bool isvalueinarray(char val, const char *arr, int size){
    int i;
    for (i=0; i < size; i++) {
        if (arr[i] == val)
            return true;
    }
    return false;
}

/*
 * 
 */
int main(int argc, char** argv) {

    string outputDatei = "geheim.txt";
    string inputDatei = "klartext.txt";
    //Die Datei offenen
    std::ofstream outputStream;
    std::ifstream inputStream;

    char rot13[] = {'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',};

    outputStream.open(outputDatei.c_str());
    inputStream.open(inputDatei.c_str());

    //Beide Datein konnte geoeffent werden
    if (outputStream && inputStream) {

        char c;

        while ((c = inputStream.get()) != EOF) {
            
            if (isvalueinarray(c,rot13,26))
            {
                outputStream << rot13[c - 'A'];
            }
            else
            {
                outputStream << c;
            }
            
        }
        
    } else {
        cout << "Inputstream/Output stream konnten nicht geoeffent werden" << endl;
    }

    outputStream.close();
    inputStream.close();
}


