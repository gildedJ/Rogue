#include "Game.h"

#include <iostream>

#include "factories.h"

#include "TileMap.h"

#include "../Systems/PlayerMovementSystem.h"
#include "../Systems/EnemyMovementSystem.h"
#include "../Systems/MovementSystem.h"
#include "../Systems/RenderSystem.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::Init(const char* title, int x, int y, int width, int height, bool fullscreen)
{
  int flags = 0;
  if (fullscreen)
  {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    std::cout << "Subsystems Initialized!..." << std::endl;

    window = SDL_CreateWindow(title, x, y, width, height, flags);
    if (window)
    {
      std::cout << "Window created!" << std::endl;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer)
    {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      std::cout << "Renderer created!" << std::endl;
    }

    tileMap = loadMap("test.map");
    makeTileMap(entityManager, tileMap);

    player = makePlayer(entityManager, Vector2{2, 2});
    for (int i = 0; i < 10; i++) {
      makeEnemy(entityManager, Vector2{ i + 3, 2 });
    }

    isRunning = true;
  }
  else
  {
    isRunning = false;
  }
}

void Game::HandleEvents()
{
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type)
  {
  case SDL_QUIT:
    isRunning = false;
    break;
  default:
    break;
  }
}

void Game::Update(float dt)
{
  PlayerMovementSystem::Update(entityManager);

  Position playerPos = entityManager.get<Position>(player);
  EnemyMovementSystem::Update(entityManager, playerPos.Value);

  MovementSystem::Update(entityManager, dt);
}

void Game::Render()
{
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);

  // Render
  RenderSystem::DrawTileMap(entityManager, renderer);
  RenderSystem::DrawEnemies(entityManager, renderer);
  RenderSystem::DrawPlayers(entityManager, renderer);

  SDL_RenderPresent(renderer);
}

void Game::CleanUp()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  std::cout << "Game cleaned" << std::endl;
}

bool Game::IsRunning()
{
  return isRunning;
}