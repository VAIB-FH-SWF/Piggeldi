//
// Created by Private on 24.04.16.
//

#include "Class.h"
#include <iostream>
#include <sstream>

Class::Class(int _value, string _name) {

    this->value = _value;
    this->name = _name;

    cout << " ==== constructor called ( this = " << this->name << " )\n";
}

Class::~Class() {

    cout << " ==== destructor called ( this = " << this->name << " )\n";
}

void Class::print() {
    cout << " ==== print called ( this = " << this << " )\n";
    cout << "name: " << this->name << " value: " << this->value << endl;
}

Class &Class::set_name(string _name) {

    this->name = _name;

    cout << " ==== set name called ( this = " << this->name << " )\n";

    return *this;
}

Class &Class::set_value(int _value) {

    this->value = _value;

    cout << " ==== set value called ( this = " << this->name << " )\n";

    return *this;
}

Class &Class::operator=(const Class &other) {

    cout << " ==== operator = called ( this = " << this->name << " other = " << other.name << " )\n";
    if(this != &other){ //Check if the classes are not the same

        this->value = other.value;
    }

    return *this;
}

Class::Class(const Class &other) {

    *this = other;

    cout << " ==== copy constructor called ( this = " << this->name << " other = " << other.name << " )\n";
}

Class Class::operator+(const Class &other) {

    int newValue = this->value + other.value;
    stringstream classNameConcat;
    classNameConcat << "x" << newValue;
    string className = classNameConcat.str();
    cout << " ==== operator + called ( this = " << this->name << " other = " << other.name << " )\n";

    return Class(newValue,className);
}

Class f(Class arg) {

    return arg;
}

Class g(Class *arg) {

    return *arg;
}



