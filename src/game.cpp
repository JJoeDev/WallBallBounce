#include "inc/game.h"
#include "SDL_error.h"
#include "SDL_events.h"
#include "SDL_render.h"
#include "SDL_video.h"
#include "inc/Vector.h"
#include "inc/ball.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

SDL_Renderer* Game::renderer { nullptr };

SDL_Texture* ballTex { nullptr };
Ball* ball { nullptr };

Game::Game(const char* Title, int Width, int Height){
    if (SDL_Init(SDL_INIT_VIDEO) == 0){
        window = SDL_CreateWindow(Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_SHOWN);
        if (window == nullptr){
            std::cerr << "WINDOW CREATION FAILED: " << SDL_GetError() << std::endl;
            return;
        }

        Game::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (Game::renderer == nullptr){
            std::cerr << "FAILED CREATION OF RENDERER: " << SDL_GetError() << std::endl;
            return;
        }

        if (!IMG_Init(IMG_INIT_PNG)){
            std::cerr << "FAILED INIT IMG LOADER: " << SDL_GetError() << std::endl;
            return;
        }
    }

    ballTex = texLoader("assets/circle.png");
    // ball takes: Position, Scale, WindowSize, Texture
    ball = new Ball(Vector2f(250, 250), Vector2f(1, 1), Vector2i(Width, Height), ballTex);

    running = true;
}

Game::~Game(){
    SDL_DestroyRenderer(Game::renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture* Game::texLoader(const char* path){
    SDL_Texture* tex { nullptr };
    tex = IMG_LoadTexture(Game::renderer, path);

    if (tex == nullptr){
        std::cerr << "FAILED TO LOAD TEXTURE: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    return tex;
}

void Game::eventHandler(){
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type){
    case SDL_QUIT:
        running = false;
    }
}

void Game::clear(){
    SDL_RenderClear(Game::renderer);
}

void Game::update(double &delta){
    ball->updateBall(delta);
}

void Game::graphics(){
    SDL_SetRenderDrawColor(Game::renderer, 152, 0, 252, 255); // THIS GETS RENDERED RIGHT
    ball->renderBall(); // THIS DOES NOT GET RENDERED RIGHT
    //SDL_RenderCopy(Game::renderer, ballTex, nullptr, nullptr); // THIS GETS RENDERED RIGHT
}

void Game::display(){
    SDL_RenderPresent(Game::renderer);
}