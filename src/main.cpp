#include "SDL_stdinc.h"
#include "SDL_timer.h"
#include "inc/game.h"
#include <iostream>

namespace deltaVars {
    Uint64 curTick = SDL_GetPerformanceCounter();
    Uint64 lastTick { 0 };
    double delta { 0 };
}

int main(int argc, char* argv[]){
    // game takes: Title, Width, Height
    Game* game = new Game("Wall Ball Bounce", 500, 500);

    // This was just to try pointers lol
    double* deltaTime = &deltaVars::delta;

    while(game->isRunning()){
        deltaVars::lastTick = deltaVars::curTick;
        deltaVars::curTick = SDL_GetPerformanceCounter();
        *deltaTime = (double)((deltaVars::curTick - deltaVars::lastTick) * 1000 / (double)SDL_GetPerformanceFrequency());

        game->eventHandler();
        game->clear();
        game->update(*deltaTime);
        game->graphics();
        game->display();

        //SDL_Delay(1000);
    }

    delete game;

    return 0;
}