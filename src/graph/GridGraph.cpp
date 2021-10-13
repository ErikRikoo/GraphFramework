//
// Created by Rikoo on 13/10/2021.
//

#include <cstring>
#include "graph/GridGraph.h"

GridGraph::GridGraph(Vector2<int> _dimension) : m_Dimension(_dimension) {
    m_Data = new GridCell[_dimension.x * _dimension.y];
}

GridGraph::~GridGraph() {
    delete[] m_Data;
}

GridGraph::GridGraph(GridGraph &_other) : GridGraph(_other.m_Dimension) {
    std::memcpy(m_Data, _other.m_Data, m_Dimension.x * m_Dimension.y * sizeof(GridCell));
}

GridCell GridGraph::operator[](Vector2<int> _index) {
    return m_Data[_index.y * m_Dimension.width() + _index.x];
}
