//
// Created by Rikoo on 13/10/2021.
//

#include "io/GraphReader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <array>


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
        std::cout << "x-y => obstacle at (x, y)\n";
        std::cin >> input;
        IGNORE_INPUT();

        while(tolower(input[0]) != 'q') {
            int whitespacePosition = input.find('-');
            Vector2<int> obstaclePosition (
                    std::stoi(input.substr(0, whitespacePosition)),
                    std::stoi(input.substr(whitespacePosition + 1))
            );
            _ret[obstaclePosition] = GridCell::Blocked;
            std::cin >> input;
            IGNORE_INPUT();
        }
    }

    void ReadFromFile(std::string _filename, GridGraph<float> &_ret) {
        std::ifstream file(_filename, std::ios::in);

        std::string buffer;
        std::getline(file, buffer);
        int dimensionX = std::stoi(buffer.data());
        std::getline(file, buffer);
        int dimensionY = std::stoi(buffer.data());
        Vector2<int> dimension(dimensionX, dimensionY);
        _ret = GridGraph<float>(dimension);
        for(int y = 0; y < dimension.y; ++y) {
            std::getline(file, buffer);
            size_t rowCharacterConsumed = 0;
            for(int x = 0; x <dimensionX; ++x) {
                size_t characterConsumed;
                float value = std::stof(buffer.substr(rowCharacterConsumed), &characterConsumed);

                _ret[Vector2<int>(x, y)] = value;
                rowCharacterConsumed += characterConsumed;
            }
        }

        file.close();
    }
}
