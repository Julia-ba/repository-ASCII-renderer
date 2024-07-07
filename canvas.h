//Julia Backa, grupa 7, Zestaw 5, 07.07.2024

#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <string>

class Canvas {
protected:
    int w, h;
public:
    Canvas(int w, int h) : w(w), h(h) {}
    virtual ~Canvas() = default;
    virtual void ustaw_pixel(int x, int y, char symbol) = 0;
    virtual void zapisz(const std::string &filename) const = 0;
};

#endif // CANVAS_H

