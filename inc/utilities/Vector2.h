//
// Created by Rikoo on 13/10/2021.
//

#ifndef GRAPHFRAMEWORK_VECTOR2_H
#define GRAPHFRAMEWORK_VECTOR2_H

template<typename T>
struct Vector2 {
    T x;
    T y;

    T width() {
        return x;
    }

    T height() {
        return y;
    }
};

#endif //GRAPHFRAMEWORK_VECTOR2_H
