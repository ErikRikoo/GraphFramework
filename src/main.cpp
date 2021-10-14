#include <iostream>
#include <io/GraphPrinter.h>
#include <io/GraphReader.h>

int main() {
    GridGraph<GridCell> graph;
    io::GraphReader::ReadFromInput(graph);
    io::GraphPrinter::Print(graph);

    char input;
    std::cin >> input;

    return 0;
}
