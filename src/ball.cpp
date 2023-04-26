#include "inc/ball.h"
#include "SDL_rect.h"
#include "SDL_render.h"
#include "inc/Vector.h"
#include "inc/game.h"
#include <iostream>

Ball::Ball(Vector2f Pos, Vector2f Scale, Vector2i WindowSize, SDL_Texture* Texture) : windowSize(WindowSize), tex(Texture), pos(Pos), scale(Scale) {
    ballRect.x = 0;
    ballRect.y = 0;
    SDL_QueryTexture(tex, nullptr, nullptr, &ballRect.w, &ballRect.h);

    float hBW = (float)ballRect.w / 2 * scale.x;
    float hBH = (float)ballRect.h / 2 * scale.y;
    ballCollider.x = (float)ballRect.x + hBW;
    ballCollider.y = (float)ballRect.y + hBH;

    Dir = VecFuncs::normalize(Dir);
}

Ball::~Ball(){
    SDL_DestroyTexture(tex);
}

void Ball::updateBall(double &delta){
    pos.x += Dir.x * speed * delta;
    pos.y += Dir.y * speed * delta;

    if (pos.x - ballCollider.x <= 0){
        Dir.x *= -1;
        VecFuncs::normalize(Dir);
        pos.x += 1;

    }
    else if (pos.x + ballCollider.x >= windowSize.x){
        Dir.x *= -1;
        VecFuncs::normalize(Dir);
        pos.x -= 1;
    }
    if (pos.y - ballCollider.y <= 0){
        Dir.y *= -1;
        VecFuncs::normalize(Dir);
        pos.y += 1;
    }
    else if (pos.y + ballCollider.y >= windowSize.y){
        Dir.y *= -1;
        VecFuncs::normalize(Dir);
        pos.y -= 1;
    }
}

void Ball::renderBall(){
    SDL_Rect dst;

    dst.x = getPos().x - ballRect.w * getScale().x / 2;
    dst.y = getPos().y - ballRect.h * getScale().y / 2;
    dst.w = ballRect.w * getScale().x;
    dst.h = ballRect.h * getScale().y;

    SDL_RenderCopyEx(Game::renderer, tex, &ballRect, &dst, 0, nullptr, SDL_FLIP_NONE);
}
