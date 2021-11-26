//
// Created by Rikoo on 10/11/2021.
//

#ifndef GRAPHFRAMEWORK_VALUEDORIENTEDGRAPH_H
#define GRAPHFRAMEWORK_VALUEDORIENTEDGRAPH_H

#include <map>
#include <utility>
#include <string>
#include <vector>

template<typename Node, typename Value>
class ValuedOrientedGraph {
    using OwnType = ValuedOrientedGraph<Node, Value>;
    using KeyType = std::pair<Node, Node>;

    std::map<
            Node,
            std::map<Node, Value>> m_Data;

public:
    void Insert(KeyType _vertices, Value _data) {
        m_Data[_vertices.first][_vertices.second] = _data;
    }

    Value operator[](KeyType _vertices) {
        return m_Data[_vertices.first][_vertices.second];
    }

    Value get(KeyType _vertices, Value _default) {
        auto firstIterator = m_Data.find(_vertices.first);
        if(firstIterator == m_Data.end()) {
            return _default;
        }

        auto secondIterator = (*firstIterator).second.find(_vertices.second);

        return secondIterator == (*firstIterator).second.end() ? _default : (*secondIterator).second;
    }

    void getNodes(std::vector<Node>& _out) {
        _out = std::vector<Node>(m_Data.size());
        for(auto [key, value]: m_Data) {
            _out.push_back(key);
        }
    }

    bool getNeighbors(Node _vertex, const std::map<Node, Value>& _ret) {
        auto iterator = m_Data.find(_vertex);
        if(iterator == m_Data.end()) {
            return false;
        }

        _ret = *iterator;
        return true;
    }



    friend std::ostream & operator<<(std::ostream & _str, const OwnType& _obj) {
        for (const auto &item : _obj.m_Data) {
            for(const auto &secondItem : item.second) {
                _str << item.first << " -> " << secondItem.first << " = " << secondItem.second << '\n';
            }
        }

        return _str;
    }
};

#endif //GRAPHFRAMEWORK_VALUEDORIENTEDGRAPH_H
