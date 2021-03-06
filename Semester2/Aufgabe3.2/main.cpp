#include <iostream>
#include <fstream>

using namespace std;

typedef unsigned int unit;

struct mitarbeiter {

    string identnummer;
    string nachname;
    string vorname;
    string abteilung;
    uint durchwahl;
    struct mitarbeiter* next;
};

int main() {

    //Read the database
    ifstream inputStream("/Users/private/Studium/C++/Piggeldi/Semester2/Aufgabe3.2/personen.dat");

    mitarbeiter *employee = new mitarbeiter();
    mitarbeiter *cursor = nullptr;
    mitarbeiter *anker    = nullptr;

    if (!inputStream){

        cout << "Personendatenbank konnte nicht gefunden werden" << endl;
    }

    int i = 0;

    //read row for row into the employee struct
    while (inputStream >> employee->identnummer >> employee->nachname >> employee->vorname >> employee->abteilung >> employee->durchwahl){

        //create a new employee
        mitarbeiter *listEmployee = new mitarbeiter;
        listEmployee->next = nullptr;

        //copy the item of the employee into the listemployee
        *listEmployee = *employee;

        if (i == 0){

            //set the anker and the first list entry
            cursor = listEmployee;
            anker  = cursor;
        }
        else {

            //update the cursor
            cursor->next = listEmployee;
            cursor = cursor->next;
        }

        i++;
    }
    inputStream.close();

    cursor = anker;

    //Loop throw the list and find the telno 4731
    while (cursor->next != nullptr){

        if (cursor->durchwahl == 4731) {

            cout << cursor->vorname << " " << cursor->nachname << endl;
        }

        cursor = cursor->next;
    }

    //CLEANUP
    cursor = anker;

    while (cursor->next != nullptr){

        mitarbeiter *cache = cursor;

        cursor = cursor->next;

        delete(cache);
    }
    //Delete the last element of the
    delete(cursor);

    return 0;
}