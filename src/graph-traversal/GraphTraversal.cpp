//
// Created by Rikoo on 08/11/2021.
//
#include <queue>
#include <algorithm>

#include "graph-traversal/GraphTraversal.h"
#include "utilities/Vector2.h"

namespace GraphTraversal {

    bool isBetweenZeroAndMax(int _value, int _max) {
        return _value >= 0 && _value < _max;
    }

    bool isVector2InDimension(const Vector2<int> &_toCheck, const Vector2<int> &_dimension) {
        return isBetweenZeroAndMax(_toCheck.x, _dimension.x) && isBetweenZeroAndMax(_toCheck.y, _dimension.y);
    }

    int getNeighbors(
            const Vector2<int> &_current, const Vector2<int> &_gridDimension,
            Vector2<int> _out[4]
    ) {
        int neighborCount = 0;
        constexpr int neighborCheckCount = 4;
        Vector2<int> _neighborsCheck[neighborCheckCount]{
                Vector2<int>(-1, 0),
                Vector2<int>(1, 0),
                Vector2<int>(0, -1),
                Vector2<int>(0, 1)
        };
        for (int i = 0; i < neighborCheckCount; ++i) {
            Vector2<int> neighbor = _current + _neighborsCheck[i];
            if (isVector2InDimension(neighbor, _gridDimension)) {
                _out[neighborCount++] = neighbor;
            }
        }

        return neighborCount;
    }

    void breadthFirstSearch(
            GridGraph::GridGraph<GridCell> &_graph, std::vector<Vector2<int>> &_path,
            const Vector2<int> &_start, const Vector2<int> &_goal
    ) {
        // (-1, -1) also means unvisited
        // If it points into grid cell then it is visited
        GridGraph<Vector2<int>> originGrid(_graph.dimension(), Vector2<int>(-1, -1));

        std::queue<Vector2<int>> queue;
        queue.push(_start);
        originGrid[_start] = _start;
        Vector2<int> neighbors[4];
        while (!queue.empty()) {
            Vector2<int> currentCell = queue.front();
            queue.pop();
            if (currentCell.x == _goal.x && currentCell.y == _goal.y) {
                break;
            }

            int neighborCount = getNeighbors(currentCell, _graph.dimension(), neighbors);
            for (int i = 0; i < neighborCount; ++i) {
                Vector2<int> neighbor = neighbors[i];
                Vector2<int> origin = originGrid[neighbor];
                if (origin.x == -1 && origin.y == -1 && _graph[neighbor] != GridCell::Blocked) {
                    originGrid[neighbor] = currentCell;
                    queue.push(neighbor);
                }
            }
        }

        Vector2<int> cell = _goal;
        do {
            _path.push_back(cell);
            cell = originGrid[cell];
        } while (cell.x != _start.x || cell.y != _start.y);
        _path.push_back(_start);

        std::reverse(_path.begin(), _path.end());
    }
}