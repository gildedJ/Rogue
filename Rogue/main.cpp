#include "Game.h"

#include <iostream>

int main(int argc, char* argv[])
{
  Game game;

  game.Init("Rogue", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);
  Uint32 lastTime = 0;
  while (game.IsRunning())
  {
    Uint32 frameTime = SDL_GetTicks();
    float dt = ((float)frameTime - lastTime) / 1000.0f;
    std::cout << (1.0f / dt) << " FPS" << std::endl;
    lastTime = frameTime;

    game.HandleEvents();
    game.Update(dt);
    game.Render();
  }
  game.CleanUp();

  return 0;
}