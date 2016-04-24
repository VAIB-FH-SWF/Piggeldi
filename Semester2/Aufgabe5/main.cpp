#include <iostream>
#include "Class.h"

using namespace std;

int main() {

    cout  << "\n ##########  Class x1(11, x1)                       ########## \n\n" << endl;
    Class x1(11, "x1");
    cout  << "\n ##########  Class x2 = x1;                       ########## \n\n" << endl;
    Class x2 = x1;
    x2.set_name("x2");
    cout  << "\n ##########  Class x3(11, x1)                       ########## \n\n" << endl;
    Class x3(33, "x3");
    cout  << "\n ##########  x3 = x1 + x2                       ########## \n\n" << endl;
    x3 = x1 + x2;
    cout  << "\n ##########  x3 = x1 + f(x2)                       ########## \n\n" << endl;
    x3 = x1 + f(x2);
    cout  << "\n ##########  x3 = x1 + g(&x2)                       ########## \n\n" << endl;
    x3 = x1 + g(&x2);
    cout  << "\n ##########  x3 = x1 + 234                       ########## \n\n" << endl;
    x3 = x1 + 234;
    cout  << "\n ##########  x3.set_value(333)                      ########## \n\n" << endl;
    x3.set_value(333);

    cout << "ENDE" << endl;
}