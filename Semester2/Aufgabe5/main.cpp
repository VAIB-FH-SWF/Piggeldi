#include <iostream>
#include "Class.h"

using namespace std;

int main() {


    Class x1(11, "x1");
    Class x2 = x1;
    x2.set_name("x2");
    Class x3(33, "x3");
    x2.set_name("x2");

    cout  << "\n ##########  x3 = x1 + 4                       ########## \n\n" << endl;

    x3.print();
    x3 = x1 + x2;
    x3.print();
}