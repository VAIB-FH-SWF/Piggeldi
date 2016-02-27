//
// Created by Private on 27.02.16.
//

#include "Board.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Board::draw(CellSphere cellCulture, uint height, uint width) {

    int aliveCells = 0;

    for (int row = 1; row < height-1; row++){

        for (int col = 1; col < width-1; col++){

            if (cellCulture[row][col].state == Alive){

                cout << "#";
                aliveCells++;
            }
            else {

                cout << " ";
            }
        }
        cout << endl;
    }

    this->generationCount++;

    cout << endl;
    cout << "Generation " << this->generationCount << " / Population  " << aliveCells << endl;
    cout << endl;
}

