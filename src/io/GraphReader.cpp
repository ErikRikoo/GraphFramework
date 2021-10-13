//
// Created by Rikoo on 13/10/2021.
//

#include "io/GraphReader.h"
#include <iostream>
#include <string>

void GraphReader::ReadFromInput(GridGraph& _ret) {
    Vector2<int> dimension;
    std::cout << "Enter the dimension one line after another, width the height\n";
    std::cin >> dimension.x;
    std::cin >> dimension.y;
    _ret = GridGraph(dimension);

    std::string input;
    std::cout << "You will now be able to enter obstacles. 'q' will stop the reading\n";
    std::cout << "x y => obstacle at (x, y)`n";
    std::cin >> input;
    while(tolower(input[0]) != 'q') {
        int whitespacePosition = input.find(' ');
        Vector2<int> obstaclePosition;
        obstaclePosition.x =
    }
}