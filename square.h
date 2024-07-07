//Julia Backa, grupa 7, Zestaw 5, 07.07.2024

#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"

class Square : public Rectangle {
public:
    Square(int x, int y, int s) : Rectangle(x, y, s, s) {}

    void draw(Canvas &c, char symbol) const override 
    {
        Rectangle::draw(c, symbol);
    }
};

#endif // SQUARE_H


