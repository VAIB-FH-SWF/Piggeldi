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

    int width = 42;
    int height = 32;

    God *theAlmighty        = new God();
    Board *battleGround     = new Board();
    Lifecycle *motherNature = new Lifecycle();

    CellSphere sphere = theAlmighty->spreadNewLife(height,width);

    while(readKeyBoardInput() != "q"){

        CellSphere newSphere = theAlmighty->createCellSphere(height,width);

        battleGround->draw(sphere,height,width);
        motherNature->evolve(sphere, newSphere, height,width);

        theAlmighty->destroySphere(sphere);

        sphere = newSphere;
    }

    theAlmighty->destroySphere(sphere);
}