//
// Created by Rikoo on 13/10/2021.
//

#ifndef GRAPHFRAMEWORK_GRAPHREADER_H
#define GRAPHFRAMEWORK_GRAPHREADER_H

#include <graph/GridGraph.h>

#define IGNORE_INPUT() std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


namespace io::GraphReader {
    void ReadFromInput(GridGraph<GridCell>& _ret);
}


#endif //GRAPHFRAMEWORK_GRAPHREADER_H
