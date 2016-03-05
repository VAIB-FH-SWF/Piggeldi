#include <iostream>
#include "God.h"
#include "Board.h"
#include "Lifecycle.h"

using namespace std;

std::string readKeyBoardInput() {

    std::string entry;

    std::cin >> entry;

    if (std::cin.fail()) {
        std::cin.clear();

        return "";
    }

    return entry;
}

int main() {

    std::cout << "Game of Life. Press any key to start" << std::endl;

    //Defined the width and heigt of the cellsphere
    int width = 42;
    int height = 32;

    //Create the almighty/the battleground and mothernature
    God *theAlmighty        = new God();
    Board *battleGround     = new Board();
    Lifecycle *motherNature = new Lifecycle();

    //Create new live in sphere
    CellSphere sphere = theAlmighty->spreadNewLife(height,width);

    while(readKeyBoardInput() != "q"){

    	//Create empty sphere
        CellSphere newSphere = theAlmighty->createCellSphere(height,width);

        //Draw the actual sphere
        battleGround->draw(sphere,height,width);
        //starts the evolving progress
        motherNature->evolve(sphere, newSphere, height,width);

        //destory the oldsphere
        theAlmighty->destroySphere(sphere);

        sphere = newSphere;
    }

    theAlmighty->destroySphere(sphere);

    //Clear everything
    delete(theAlmighty);
    delete(battleGround);
    delete(motherNature);
}
