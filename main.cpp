//Julia Backa, grupa 7, Zestaw 5, 07.07.2024

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <limits>
#include "asciicanvas.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"
#include <iomanip>


std::unique_ptr<Figure> figura(const std::string &typ, std::istringstream &iss) {
    if (typ == "Circle") {
        int x, y, r;
        if (!(iss >> x >> y >> r)) 
        {
            std::cerr << "Blad wczytywania parametrow\n";
            return nullptr;
        }
        return std::make_unique<Circle>(x, y, r);
    } else if (typ == "Square") 
    {
        int x, y, s;
        if (!(iss >> x >> y >> s)) 
        {
            std::cerr << "Blad wczytywania parametrow\n";
            return nullptr;
        }
        return std::make_unique<Square>(x, y, s);
    } else if (typ == "Rectangle") 
    {
        int x, y, w, h;
        if (!(iss >> x >> y >> w >> h)) 
        {
            std::cerr << "Blad wczytywania parametrow\n";
            return nullptr;
        }
        return std::make_unique<Rectangle>(x, y, w, h);
    } else 
    {
        std::cerr << "Nieznana figura: " << typ << '\n';
        return nullptr;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) 
    {
        std::cerr << "Bledne uzycie wpisz: " << argv[0] << " <plik konfiguracyjny>\n";
        return 1;
    }

    std::ifstream kon_file(argv[1]);
    if (!kon_file) 
    {
        std::cerr << "Error opening configuration file: " << argv[1] << '\n';
        return 1;
    }

    int Width, Height;
    std::string output_file;
    std::string tlo_str;
    char symbol_tla;

    if (!(kon_file >> Width >> Height)) 
    {
        std::cerr << "Blad wczytywania wymiarow canvas\n";
        return 1;
    }

    if (!(kon_file >> output_file)) 
    {
        std::cerr << "Failed to read output file name\n";
        return 1;
    }

        if (!(kon_file >> std::ws >> std::quoted(tlo_str))) 
        {
        std::cerr << "Blad wczytywania symbolu tla\n";
        return 1;
    }
    symbol_tla = tlo_str[0];

    ASCIICanvas canvas(Width, Height, symbol_tla);

    std::string typ;
    while (kon_file >> typ) 
    {
        std::string l;
        std::getline(kon_file >> std::ws, l); 

        std::istringstream iss(l);
        auto figure = figura(typ, iss);
        if (figure) 
        {
            std::string symbol;
            if (!(kon_file >> std::quoted(symbol)) )
            {
                std::cerr << "Blad wczytywania symbolu dla figury: " << typ << '\n';
                return 1;
            }
            figure->draw(canvas, symbol[0]);

            kon_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    canvas.zapisz(output_file);

    return 0;
}




