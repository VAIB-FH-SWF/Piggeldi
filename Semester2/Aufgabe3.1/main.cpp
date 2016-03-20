#include <iostream>

using namespace std;

struct Element {

    long key;
    long info;
    struct Element *next;

};

int main() {

    Element* L = nullptr;
    Element* cursor = nullptr;

    //create the elements
    Element* x4 = new Element();
    x4->key = 4;
    x4->info = 44;
    x4->next = nullptr;

    Element* x3 = new Element();
    x3->info = 33;
    x3->key = 3;
    x3->next = x4;

    Element* x2 = new Element();
    x2->key = 2;
    x2->info = 22;
    x2->next = x3;

    Element* x1 = new Element();
    x1->key = 1;
    x1->info = 11;
    x1->next = x2;

    L = x1;
    cursor = L;

    while (cursor->key != 3){

        cursor = cursor->next;
    }

    if (cursor->key == 3){

        cout << "Listenelement gefunden :" << cursor << endl;
        cout << "key = \t\t\t\t\t" << cursor->key << endl;
        cout << "info = \t\t\t\t\t" << cursor->info << endl;
        cout << "next = \t\t\t\t\t" << cursor->next << endl;
    }

    //CLEANUP!

    delete(x1);
    delete(x2);
    delete(x3);
    delete(x4);

    return 0;
}