#ifndef BALL_H
#define BALL_H
#include "SDL_rect.h"
#include "SDL_render.h"
#include "Vector.h"

class Ball{
protected:
    Vector2f Dir { 1, 0.7 };

public:
    Ball(Vector2f Pos, Vector2f Scale, Vector2i WindowSize, SDL_Texture* Texture);
    ~Ball();

    Vector2f& getPos() { return pos; }
    Vector2f& getScale() { return scale; }

    void updateBall(double& delta);
    void renderBall();

private:
    Vector2f pos { 0, 0 };
    Vector2f scale { 1, 1 };
    Vector2f ballCollider { 1, 1};
 
    float speed { 0.2 };
    
    Vector2i windowSize { 0, 0 };

    SDL_Rect ballRect { 0, 0, 0, 0 };
    SDL_Texture* tex { nullptr };
};

#endif