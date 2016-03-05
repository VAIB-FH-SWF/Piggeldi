//
// Created by Private on 27.02.16.
//

#ifndef AUFGABE2_GOD_H
#define AUFGABE2_GOD_H

#include "Cell.h"

typedef Cell** CellSphere;
/**
 * The almighty god who give and take life
 */
class God {

public:

	/**
	 * Creates a new cellsphere with life
	 * @param rows cellsphere rows
	 * @param columns cellsphere colums
	 * @return created cellsphere with life
	 */
    CellSphere spreadNewLife(int rows, int columns);

    /**
     * Destroies the cellsphere
     * @param cellCulture destroying cellculture
     */
    void destroySphere(CellSphere cellCulture);

    /**
     * Creates an empty cellsphere without life
     * @param rows cellsphere rows
     * @param column cellsphere columns
     * @return empty cellsphere
     */
    CellSphere createCellSphere(int rows, int columns);
};


#endif //AUFGABE2_GOD_H
