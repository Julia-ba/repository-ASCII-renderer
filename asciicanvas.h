//Julia Backa, grupa 7, Zestaw 5, 07.07.2024

#ifndef ASCIICANVAS_H
#define ASCIICANVAS_H

#include "canvas.h"
#include <fstream>
#include <cstdlib>

class ASCIICanvas : public Canvas {
private:
    std::vector<std::vector<char>> siatka;
public:
    ASCIICanvas(int w, int h, char tlo) : Canvas(w, h), siatka(h, std::vector<char>(w, tlo)) {}
    
    void ustaw_pixel(int x, int y, char symbol) override 
    {
        if (x >= 0 && x < w && y >= 0 && y < h) 
        {
            siatka[y][x] = symbol;
        }else {
            std::cerr << "piksel (" << x << ", " << y << ") nieprawidlowa wartosc\n";
            std::exit(EXIT_FAILURE);
        }
    }

    void zapisz(const std::string &file_name) const override 
    {
        std::ofstream file(file_name, std::ios::out);
        if (!file) 
        {
            std::cerr << "Error opening file: " << file_name << '\n';
            return;
        }
        for (const auto& l : siatka) 
        {
            for (const auto& ch : l) 
            {
                file.put(ch);
            }
            file.put('\n');
        }
    }
};

#endif // ASCIICANVAS_H


