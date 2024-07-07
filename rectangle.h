//Julia Backa, grupa 7, Zestaw 5, 07.07.2024

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure {
protected:
    int x, y, w, h;
public:
    Rectangle(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}

    void draw(Canvas &c, char symbol) const override 
    {
        for (int i = 0; i < w; ++i) 
        {
            for (int j = 0; j < h; ++j) 
            {
                c.ustaw_pixel(x + i, y + j, symbol);
            }
        }
    }
};

#endif // RECTANGLE_H


