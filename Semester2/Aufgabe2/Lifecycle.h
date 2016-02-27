//
// Created by Private on 27.02.16.
//

#ifndef AUFGABE2_LIFECYCLE_H
#define AUFGABE2_LIFECYCLE_H


#include "God.h"

class Lifecycle {

public:

    void evolve(CellSphere oldSphere, CellSphere newSphere, int rows, int columns);

private:

    int numberOfAliveNeighbours(CellSphere sphere, int posX, int posY);

    void naturalSelection(Cell &cell, int aliveNeighbours);
};


#endif //AUFGABE2_LIFECYCLE_H
