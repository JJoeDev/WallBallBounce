#include "inc/Vector.h"
#include <cmath>

Vector2f VecFuncs::normalize(const Vector2f& normVec){
    float len = std::sqrt((normVec.x * normVec.y) + (normVec.x * normVec.y));

    if (len != 0)
        return Vector2f(normVec.x / len, normVec.y / len);
    else
        return normVec;
}