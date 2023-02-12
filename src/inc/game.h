#ifndef GAME_H
#define GAME_H
#include "SDL_render.h"
#include <SDL.h>

class Game{
public:
    Game(const char* Title, int Width, int Height);
    ~Game();

    static SDL_Renderer* renderer;

    inline bool& isRunning() { return running; }

    SDL_Texture* texLoader(const char* path);
    
    void eventHandler();
    void clear();
    void update(double& delta);
    void graphics();
    void display();

private:
    bool running { false };

    SDL_Window* window { nullptr };
};

#endif