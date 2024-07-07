//Julia Backa, grupa 7, Zestaw 5, 07.07.2024

#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

class Circle : public Figure {
private:
    int x, y, r;
public:
    Circle(int x, int y, int r) : x(x), y(y), r(r) {}

    void draw(Canvas &c, char symbol) const override 
    {
        for (int i = -r ; i <= r; ++i) 
        {
            for (int j = -r ; j <= r; ++j) 
            {
                if (i*i + j*j <= r*r) 
                {
                    c.ustaw_pixel(x + i, y + j, symbol);
                }
            }
        }
    }
};

#endif // CIRCLE_H


