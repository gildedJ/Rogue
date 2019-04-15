#pragma once

#include "SDL.h"
#include "../Util/ECS.h"

#include "TileMap.h"

class Game
{
public:
  Game();
  ~Game();

  void Init(const char* title, int x, int y, int width, int height, bool fullscreen);

  void HandleEvents();
  void Update(float dt);
  void Render();
  void CleanUp();

  bool IsRunning();

private:
  bool isRunning;
  SDL_Window* window;
  SDL_Renderer* renderer;
  EntityManager entityManager;
  TileMap tileMap;
  Entity player;
};

