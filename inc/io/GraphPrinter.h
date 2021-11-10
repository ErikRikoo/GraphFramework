//
// Created by ErikKubiak on 14/10/2021.
//

#ifndef GRAPHFRAMEWORK_GRAPHPRINTER_H
#define GRAPHFRAMEWORK_GRAPHPRINTER_H

#include <vector>

#include <graph/GridGraph.h>

namespace io::GraphPrinter {
    void Print(GridGraph<GridCell>& _toDisplay);
    void Print(GridGraph<GridCell>& _toDisplay, std::vector<Vector2<int>>& _path);
    void ComputeDisplayGrid(GridGraph<GridCell>& _toDisplay, GridGraph<char>& _ret);
    void AddPathToDisplay(GridGraph<char>& _display, std::vector<Vector2<int>>& _path);

    template <typename T>
    void Print(GridGraph<T>& _toDisplay, std::string _cellDelimiter = "") {
        Vector2<int> dimension = _toDisplay.dimension();
        for(int y = 0; y < dimension.height(); ++y) {
            for (int x = 0; x < dimension.width(); ++x) {
                Vector2<int> position(x, y);
                std::cout << _toDisplay[position] << _cellDelimiter;
            }
            std::cout << std::endl;
        }
    }
}


#endif //GRAPHFRAMEWORK_GRAPHPRINTER_H
