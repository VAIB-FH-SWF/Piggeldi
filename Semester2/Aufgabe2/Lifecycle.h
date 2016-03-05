//
// Created by Private on 27.02.16.
//

#ifndef AUFGABE2_LIFECYCLE_H
#define AUFGABE2_LIFECYCLE_H


#include "God.h"

class Lifecycle {

public:

	/**
	 * Starts an evoling process on oldSphere into a newSphere
	 * @param oldSphere to evolve
	 * @param newSphere evoled
	 * @param rows sphere rows
	 * @param columns sphere columns
	 */
    void evolve(CellSphere oldSphere, CellSphere newSphere, int rows, int columns);

private:

    /**
     * Returns the number of alived neightbours for the given coordinates
     * @param sphere sphere to check
     * @param posX xpos of the cell in the sphere
     * @param posY xpod of the cell in the sphere
     * @return
     */
    int numberOfAliveNeighbours(CellSphere sphere, int posX, int posY);

    /**
     * Starts the natural selection for the given cell
     * @param cell live/dead cell
     * @param aliveNeighbours number of alived neighbours
     */
    void naturalSelection(Cell &cell, int aliveNeighbours);
};


#endif //AUFGABE2_LIFECYCLE_H
