//
// Created by Rikoo on 08/11/2021.
//

#ifndef GRAPHFRAMEWORK_GRAPHTRAVERSAL_H
#define GRAPHFRAMEWORK_GRAPHTRAVERSAL_H

#include  "graph/GridGraph.h"

namespace GraphTraversal{
    void breadthFirstSearch(
            GridGraph<GridCell>& _graph, std::vector<Vector2<int>>& _path,
            const Vector2<int>& _start, const Vector2<int>& _goal
    );

}

#endif //GRAPHFRAMEWORK_GRAPHTRAVERSAL_H
