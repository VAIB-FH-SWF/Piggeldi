//
// Created by Private on 27.02.16.
//

#include "God.h"

#include <cstdlib>
#include <iostream>

CellSphere God::spreadNewLife(int rows, int columns) {

    CellSphere sphere = this->createCellSphere(rows, columns);

    std:srand(std::time(0));

    for (int row = 0; row < rows; row++){

        for (int col = 0; col < columns; col++){

            //Init the margin with dead cells
            if (row == 0 || col == 0 || row == rows -1 || col == columns -1) {

                sphere[row][col].state = Dead;
            }
            else {

                sphere[row][col].state = (CellState)(std::rand() % 2);
            }
        }
    }

    return sphere;
}

void God::destroySphere(CellSphere cellCulture) {

    delete[] *cellCulture;
    delete[] cellCulture;
}

CellSphere God::createCellSphere(int rows, int columns) {

    int i;
    CellSphere sphere;

    sphere  = new Cell* [rows];
    *sphere = new Cell [rows * columns]();

    for (i = 1; i < rows; i+=1){
        sphere[i] = sphere[i-1] + columns;
    }
    return sphere;
}
