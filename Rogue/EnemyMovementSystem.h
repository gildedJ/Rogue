#pragma once

#include "SDL.h"
#include "ECS.h"

#include "Position.h"
#include "Acceleration.h"
#include "Enemy.h"


class EnemyMovementSystem {
public:

  static void Update(EntityManager& entityManager, Vector2 playerPos)
  {
    const float EnemyAcceleration = 350.0f;

    auto view = entityManager.view<Position, Acceleration, Enemy>();
    for (auto entity : view)
    {
      auto& position = view.get<Position>(entity);
      auto& acceleration = view.get<Acceleration>(entity);

      Vector2 heading = normalize(playerPos - position.Value);
      acceleration.Value = heading * EnemyAcceleration;
    }
  }
};