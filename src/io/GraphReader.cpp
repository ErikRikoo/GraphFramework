//
// Created by Rikoo on 13/10/2021.
//

#include "io/GraphReader.h"
#include <iostream>
#include <string>

#define IGNORE_INPUT() std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

namespace io::GraphReader {
    void ReadFromInput(GridGraph<GridCell>& _ret) {

        std::cout << "Enter the dimension one line after another, width then height\n";
        int x;
        std::cin >> x;
        IGNORE_INPUT();

        int y;
        std::cin >> y;
        IGNORE_INPUT();


        Vector2<int> dimension(x, y);
        _ret = GridGraph<GridCell>(dimension, GridCell::Traversable);

        std::string input;
        std::cout << "You will now be able to enter obstacles. 'q' will stop the reading\n";
        std::cout << "x y => obstacle at (x, y)\n";
        std::cin >> input;
        IGNORE_INPUT();

        while(tolower(input[0]) != 'q') {
            int whitespacePosition = input.find(' ');
            Vector2<int> obstaclePosition (
                    std::stoi(input.substr(0, whitespacePosition)),
                    std::stoi(input.substr(whitespacePosition + 1))
            );
            _ret[obstaclePosition] = GridCell::Blocked;
            std::cin >> input;
            IGNORE_INPUT();
        }
    }
}
