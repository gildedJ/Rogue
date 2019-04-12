#pragma once

#include "entt\entity\registry.hpp"

#include "Acceleration.h"
#include "Velocity.h"
#include "Position.h"


class MovementSystem {
public:
  static void Update(entt::registry& entityManager, float dt)
  {
    entityManager.view<Position, Velocity, Acceleration>().each([dt](auto& position, auto& velocity, auto& acceleration) {
      velocity.Value += (velocity.Value * -0.5f + acceleration.Value) * dt;

      if (velocity.Value.X > velocity.Limit.X)
      {
        velocity.Value.X = velocity.Limit.X;
      }
      if (velocity.Value.X < -velocity.Limit.X)
      {
        velocity.Value.X = -velocity.Limit.X;
      }
      if (velocity.Value.Y > velocity.Limit.Y)
      {
        velocity.Value.Y = velocity.Limit.Y;
      }
      if (velocity.Value.Y < -velocity.Limit.Y)
      {
        velocity.Value.Y = -velocity.Limit.Y;
      }

      position.Value += velocity.Value * dt;
    });
  }
};