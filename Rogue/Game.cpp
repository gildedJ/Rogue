#include "Game.h"

#include <iostream>

#include "Player.h"
#include "Enemy.h"
#include "Sprite.h"
#include "Acceleration.h"
#include "Velocity.h"
#include "Position.h"

#include "PlayerMovementSystem.h"
#include "EnemyMovementSystem.h"
#include "MovementSystem.h"
#include "RenderSystem.h"


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

    player = entityManager.create();
    entityManager.assign<Position>(player, Vector2{ 50.0f, 50.0f });
    entityManager.assign<Sprite>(player, Vector2{ 0.0f, 0.0f }, Dimension{ 50.0f, 50.0f }, Color{ 0.35f, 0.8f, 0.3f, 1.0f });
    entityManager.assign<Velocity>(player, Vector2{ 0.0f, 0.0f }, Vector2{ 200.0f, 200.0f });
    entityManager.assign<Acceleration>(player, Vector2{ 0.0f, 0.0f });
    entityManager.assign<Player>(player);

    for (int i = 0; i < 10; i++) {
      auto enemy = entityManager.create();
      entityManager.assign<Position>(enemy, Vector2{ i * 100.0f, 200.0f });
      entityManager.assign<Sprite>(enemy, Vector2{ 0.0f, 0.0f }, Dimension{ 50.0f, 50.0f }, Color{ 0.8f, 0.35f, 0.2f, 1.0f });
      entityManager.assign<Velocity>(enemy, Vector2{ 0.0f, 0.0f }, Vector2{ 150.0f, 150.0f });
      entityManager.assign<Acceleration>(enemy, Vector2{ 0.0f, 0.0f });
      entityManager.assign<Enemy>(enemy);
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
  RenderSystem::Update(entityManager, renderer);

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