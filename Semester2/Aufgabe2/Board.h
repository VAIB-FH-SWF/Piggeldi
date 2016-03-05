//
// Created by Private on 27.02.16.
//

#ifndef AUFGABE2_BOARD_H
#define AUFGABE2_BOARD_H

#include "Cell.h"
#include "God.h"

typedef unsigned int uint;

class Board {

public:
    void draw(CellSphere cellCulture, uint height, uint width);
private:

    int generationCount = 0;
};


#endif //AUFGABE2_BOARD_H
