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
        GridGraph<char> display;
        ComputeDisplayGrid(_toDisplay, display);
        Print(display);
    }

    void Print(GridGraph<GridCell>& _toDisplay, std::vector<Vector2<int>>& _path) {
        GridGraph<char> display;
        ComputeDisplayGrid(_toDisplay, display);
        AddPathToDisplay(display, _path);
        Print(display);
    }

    void ComputeDisplayGrid(GridGraph<GridCell>& _toDisplay, GridGraph<char>& _ret) {
        Vector2<int> dimension = _toDisplay.dimension();
        _ret = GridGraph<char>(dimension);
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
                _ret[position] = out;
            }
        }
    }

    void AddPathToDisplay(GridGraph<char>& _display, std::vector<Vector2<int>>& _path) {
        if(_path.size() < 2) {
            return;
        }

        int lastElementIndex = _path.size() - 1;
        _display[_path[0]] = 'x';
        _display[_path[lastElementIndex]] = 'x';
        for(int i = 1; i < lastElementIndex; ++i) {
            Vector2<int>& position = _path[i];
            Vector2<int>& nextPosition = _path[i + 1];
            Vector2<int> direction = nextPosition - position;

            // Taking assumption that we will only get the N O S and E direction
            if(direction.x == -1) {
                _display[position] = '<';
            } else if(direction.x == 1) {
                _display[position] = '>';
            }

            if(direction.y == -1) {
                _display[position] = '^';
            } else if(direction.y == 1) {
                _display[position] = 'v';
            }
        }
    }
};