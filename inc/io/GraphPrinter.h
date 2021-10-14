//
// Created by ErikKubiak on 14/10/2021.
//

#ifndef GRAPHFRAMEWORK_GRAPHPRINTER_H
#define GRAPHFRAMEWORK_GRAPHPRINTER_H

#include <graph/GridGraph.h>

namespace io::GraphPrinter {
    void Print(GridGraph<char>& _toDisplay);
    void Print(GridGraph<GridCell>& _toDisplay);
}


#endif //GRAPHFRAMEWORK_GRAPHPRINTER_H
