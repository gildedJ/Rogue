#pragma once

#include "SDL.h"
#include "entt\entity\registry.hpp"

#include "Acceleration.h"
#include "Player.h"

class PlayerMovementSystem {
public:

  static void Update(entt::registry& entityManager)
  {
    const float PlayerAcceleration = 500.0f;
    float ddx = 0.0f;
    float ddy = 0.0f;

    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    if (currentKeyStates[SDL_SCANCODE_W])
    {
      ddy = -PlayerAcceleration;
    }
    if (currentKeyStates[SDL_SCANCODE_A])
    {
      ddx = -PlayerAcceleration;
    }
    if (currentKeyStates[SDL_SCANCODE_S])
    {
      ddy = PlayerAcceleration;
    }
    if (currentKeyStates[SDL_SCANCODE_D])
    {
      ddx = PlayerAcceleration;
    }
    auto view = entityManager.view<Acceleration, Player>();
    
    for (auto entity : view)
    {
      auto& acceleration = view.get<Acceleration>(entity);
      acceleration.Value.X = ddx;
      acceleration.Value.Y = ddy;
    }
  }
};