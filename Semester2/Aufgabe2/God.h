//
// Created by Private on 27.02.16.
//

#ifndef AUFGABE2_GOD_H
#define AUFGABE2_GOD_H

#include "Cell.h"

typedef Cell** CellSphere;

class God {

public:

    CellSphere spreadNewLife(int rows, int columns);

    void destroySphere(CellSphere cellCulture);

    CellSphere createCellSphere(int rows, int columns);
};


#endif //AUFGABE2_GOD_H
