//
// Created by Rikoo on 13/10/2021.
//

#ifndef GRAPHFRAMEWORK_GRAPHREADER_H
#define GRAPHFRAMEWORK_GRAPHREADER_H

#include <graph/GridGraph.h>
#include <graph/ValuedOrientedGraph.h>
#include <string>

#define IGNORE_INPUT() std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');



namespace io::GraphReader {
    void ReadFromInput(GridGraph<GridCell>& _ret);
    void ReadFromFile(const std::string& _filename, GridGraph<float> &_ret);
    void ReadFromFile(const std::string& _filename, ValuedOrientedGraph<std::string, float> &_ret,
                      bool shouldBeNonOriented = false );
}


#endif //GRAPHFRAMEWORK_GRAPHREADER_H
