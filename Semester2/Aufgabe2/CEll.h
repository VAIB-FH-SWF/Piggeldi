//
// Created by Private on 27.02.16.
//

#ifndef AUFGABE2_ZELLE_H
#define AUFGABE2_ZELLE_H

enum CellState: int {

    Dead = 0,
    Alive = 1
};
//The cell
struct Cell {

    CellState state = Dead;
};


#endif //AUFGABE2_ZELLE_H
