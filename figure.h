//Julia Backa, grupa 7, Zestaw 5, 07.07.2024

#ifndef FIGURE_H
#define FIGURE_H

#include "canvas.h"

class Figure {
public:
    virtual ~Figure() = default;
    virtual void draw(Canvas &c, char symbol) const = 0;
};

#endif // FIGURE_H

