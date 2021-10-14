//
// Created by ErikKubiak on 14/10/2021.
//

#include <iostream>

#include "io/GraphPrinter.h"
namespace io::GraphPrinter {
    void Print(GridGraph<char>& _toDisplay) {
        Vector2<int> dimension = _toDisplay.dimension();
        for(int y = 0; y < dimension.height(); ++y) {
            for (int x = 0; x < dimension.width(); ++x) {
                Vector2<int> position(x, y);
                std::cout << _toDisplay[position];
            }
            std::cout << std::endl;
        }
    }

    void Print(GridGraph<GridCell>& _toDisplay) {
        Vector2<int> dimension = _toDisplay.dimension();
        GridGraph<char> display(dimension);
        for(int y = 0; y < dimension.height(); ++y) {
            for (int x = 0; x < dimension.width(); ++x) {
                Vector2<int> position(x, y);
                char out;
                switch (_toDisplay[position]) {
                    case GridCell::Blocked:
                        out = 'x';
                        break;
                    default:
                        out = ' ';
                }
                display[position] = out;
            }
        }

        Print(display);
    }
};