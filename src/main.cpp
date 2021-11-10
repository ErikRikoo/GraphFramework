#include <iostream>
#include <io/GraphPrinter.h>
#include <io/GraphReader.h>

int main() {
//    GridGraph<GridCell> graph;
//    io::GraphReader::ReadFromInput(graph);
//    io::GraphPrinter::Print(graph);

    GridGraph<float> graph;
    io::GraphReader::ReadFromFile("../data/valued-graph/simple", graph);
    io::GraphPrinter::Print<float>(graph, " ");


//    GridGraph<GridCell> graph2(Vector2<int>(5, 5));
//    std::vector<Vector2<int>> path;
//    path.emplace_back(0, 0);
//    path.emplace_back(1, 0);
//    path.emplace_back(2, 0);
//    path.emplace_back(2, 1);
//    path.emplace_back(2, 2);
//    path.emplace_back(3, 2);
//    io::GraphPrinter::Print(graph2, path);


    return 0;
}
