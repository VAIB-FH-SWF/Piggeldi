//
// Created by Private on 24.04.16.
//

#ifndef AUFGABE5_CLASS_H
#define AUFGABE5_CLASS_H

#include <string>

using namespace std;

class Class { public:
    // ====================  LIFECYCLE     =======================================
    Class ( int _value=0, string _name="" );
    Class ( const Class &other );
    ~Class ();

// ==================== ACCESSORS
    void print ( );

// ==================== MUTATORS
    Class& set_name ( string _name );
    Class& set_value ( int _value );

// ==================== OPERATORS
    Class& operator = ( const Class &other );
    Class operator + ( const Class &other );

private:
// ==================== DATA MEMBERS ======================================= int value;
    string name;
    int value;
}; // ----- end of class Class -----

Class f ( Class arg ); // prototyp function f Class g ( Class *arg ); // prototyp function g
Class g ( Class *arg );

#endif //AUFGABE5_CLASS_H
