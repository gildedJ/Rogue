#pragma once

#include "SDL.h"
#include "entt\entity\registry.hpp"

#include "Position.h"
#include "Acceleration.h"
#include "Enemy.h"

class EnemyMovementSystem {
public:

  static void Update(entt::registry& entityManager, Vector2 playerPos)
  {
    const float EnemyAcceleration = 350.0f;

    auto view = entityManager.view<Position, Acceleration, Enemy>();
    for (auto entity : view)
    {
      auto& position = view.get<Position>(entity);
      auto& acceleration = view.get<Acceleration>(entity);

      Vector2 heading = (playerPos - position.Value).normalize();
      acceleration.Value = heading * EnemyAcceleration;
    }
  }
};