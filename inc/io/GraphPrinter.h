//
// Created by ErikKubiak on 14/10/2021.
//

#ifndef GRAPHFRAMEWORK_GRAPHPRINTER_H
#define GRAPHFRAMEWORK_GRAPHPRINTER_H

#include <vector>

#include <graph/GridGraph.h>

namespace io::GraphPrinter {
    void Print(GridGraph<char>& _toDisplay);
    void Print(GridGraph<GridCell>& _toDisplay);
    void Print(GridGraph<GridCell>& _toDisplay, std::vector<Vector2<int>>& _path);
    void ComputeDisplayGrid(GridGraph<GridCell>& _toDisplay, GridGraph<char>& _ret);
    void AddPathToDisplay(GridGraph<char>& _display, std::vector<Vector2<int>>& _path);
}


#endif //GRAPHFRAMEWORK_GRAPHPRINTER_H
