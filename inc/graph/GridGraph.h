//
// Created by Rikoo on 13/10/2021.
//

#ifndef GRAPHFRAMEWORK_GRIDGRAPH_H
#define GRAPHFRAMEWORK_GRIDGRAPH_H

#include "utilities/Vector2.h"

enum GridCell {
    Blocked,
    Traversable,
};

class GridGraph {
    explicit GridGraph(Vector2<int> _dimension);
    GridGraph(GridGraph& _other);
    virtual ~GridGraph();

    GridCell operator[](Vector2<int> _index);

private:
    GridCell* m_Data;
    Vector2<int> m_Dimension;
};


#endif //GRAPHFRAMEWORK_GRIDGRAPH_H
