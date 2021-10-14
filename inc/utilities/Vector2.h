//
// Created by Rikoo on 13/10/2021.
//

#ifndef GRAPHFRAMEWORK_VECTOR2_H
#define GRAPHFRAMEWORK_VECTOR2_H

template<typename T>
struct Vector2 {
    T x;
    T y;

    Vector2() = default;

    Vector2(T _x, T _y) : x(_x), y(_y) {}

    T width() const {
        return x;
    }

    T height() const {
        return y;
    }
};

#endif //GRAPHFRAMEWORK_VECTOR2_H
