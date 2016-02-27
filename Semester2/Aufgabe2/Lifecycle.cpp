//
// Created by Private on 27.02.16.
//

#include "Lifecycle.h"

void Lifecycle::evolve(CellSphere oldSphere, CellSphere newSphere, int rows, int columns) {

    for (int row = 1; row < rows -1; row ++){

        for (int col = 1; col < columns-1; col ++){

            Cell cell = oldSphere[row][col];

            int aliveNeighbours = this->numberOfAliveNeighbours(oldSphere, row, col);

            this->naturalSelection(cell, aliveNeighbours);

            newSphere[row][col] = cell;
        }
    }
}

int Lifecycle::numberOfAliveNeighbours(CellSphere sphere, int row, int col) {

    int alivedCells = 0;

    for (int posY = row -1; posY <= row +1; posY ++){

        for (int posX = col -1; posX <= col + 1; posX ++){

            if (posX == col && posY == row) {

               continue;
            }

            if (sphere[posY][posX].state == Alive) {
                alivedCells++;
            }
        }
    }

    return alivedCells;
}

void Lifecycle::naturalSelection(Cell& cell, int aliveNeighbours) {

    if (aliveNeighbours == 3 && cell.state == Dead){

        cell.state = Alive;
    }
    else if (aliveNeighbours < 2){

        cell.state = Dead;
    }
    else if (aliveNeighbours == 3 || aliveNeighbours == 2 && cell.state == Alive){
        cell.state = Alive;
    }
    else if (aliveNeighbours > 3){

        cell.state = Dead;
    }
}