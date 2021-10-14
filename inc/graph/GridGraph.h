//
// Created by Rikoo on 13/10/2021.
//

#ifndef GRAPHFRAMEWORK_GRIDGRAPH_H
#define GRAPHFRAMEWORK_GRIDGRAPH_H

#include <cstring>
#include "utilities/Vector2.h"

enum GridCell {
    Traversable,
    Blocked,
};

template <typename T>
class GridGraph {
public:
    GridGraph() {}

    explicit GridGraph(Vector2<int> _dimension) : m_Dimension(_dimension) {
        m_Data = new T[_dimension.x * _dimension.y];
    }

    GridGraph(Vector2<int> _dimension, T defaultValue) : GridGraph(_dimension) {
        int start = _dimension.x * _dimension.y - 1;
        for(; start >= 0; --start) {
            m_Data[start] = defaultValue;
        }
    }

    GridGraph(GridGraph& _other) : GridGraph(_other.m_Dimension) {
        std::memcpy(m_Data, _other.m_Data, m_Dimension.x * m_Dimension.y * sizeof(T));
    }

    virtual ~GridGraph() {
        delete[] m_Data;
    }

    T& operator[](const Vector2<int> _index) {
        return m_Data[_index.y * m_Dimension.width() + _index.x];
    }

    const Vector2<int>& dimension() const {
        return m_Dimension;
    }

private:
    T* m_Data;
    Vector2<int> m_Dimension;
};


#endif //GRAPHFRAMEWORK_GRIDGRAPH_H
