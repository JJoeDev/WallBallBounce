#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>

struct Vector2f{
    Vector2f(float X, float Y) : x(X), y(Y){}
    Vector2f() : x(0.0f), y(0.0f){}

    float x, y;
};

struct Vector2i{
    Vector2i(int X, int Y) : x(X), y(Y){}
    Vector2i() : x(0), y(0){}

    int x, y;
};

namespace VecFuncs {
    Vector2f normalize(const Vector2f& normVec);
}

#endif