/* 
 * File:   Pixel.h
 * Author: fredde
 *
 * Created on 31. Oktober 2015, 15:27
 */

#ifndef PIXEL_H
#define	PIXEL_H

#include <vector>

class Pixel
{
public:

    /**
     * Erzeugt ein Pixel mit den koordinaten im Bild sowie dem char wert
     * @param x 
     * @param y
     * @param value
     */
    Pixel(int x, int y, unsigned char value)
    {
        this->x = x;
        this->y = y;
        this->value = value;
    };

    int getX()
    {
        return this->x;
    }

    int getY()
    {
        return this->y;
    }

    int getValue()
    {
        return this->value;
    }

private:
    int x, y = 0;
    char value = '\0';
};

#endif	/* PIXEL_H */

