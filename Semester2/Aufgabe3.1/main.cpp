#include <iostream>

using namespace std;

struct Element {

    long key;
    long info;
    struct Element *next;

};

int main() {

    Element *L = nullptr;
    Element *cursor = nullptr;

    //Create the list
    for (int i = 1; i <= 4; i ++){

        Element *element = new Element();
        element->info = i*10+i;
        element->key = i;
        element->next = nullptr;

        if (i == 1){

            cursor = element;
            L = element;
        }
        else {

            cursor->next = element;
            cursor = element;
        }
    }

    //Set the startpoint of the list
    cursor = L;
    //Loop throw the list
    while (cursor->key != 3){

        cursor = cursor->next;

        //Break the loop i case we found a nullptr
        if (cursor->next == nullptr) {
            break;
        }
    }

    //Print the element
    if (cursor->key == 3){

        cout << "Listenelement gefunden :" << cursor << endl;
        cout << "key = \t\t\t\t\t" << cursor->key << endl;
        cout << "info = \t\t\t\t\t" << cursor->info << endl;
        cout << "next = \t\t\t\t\t" << cursor->next << endl;
    }

    //Cleanup
    cursor = L;

    while (cursor->next != nullptr) {

        Element *cache = cursor;
        cursor = cursor->next;
        delete(cache);
    }

    delete(cursor);

    return 0;
}