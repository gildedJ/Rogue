#pragma once

#include "../Util/ECS.h"

#include "../Components/Acceleration.h"
#include "../Components/Velocity.h"
#include "../Components/Position.h"


class MovementSystem {
public:
  static void Update(EntityManager& entityManager, float dt)
  {
    entityManager.view<Position, Velocity, Acceleration>().each([dt](auto& position, auto& velocity, auto& acceleration) {
      velocity.Value += (velocity.Value * -0.5f + acceleration.Value) * dt;

      if (velocity.Value.x > velocity.Limit.x)
      {
        velocity.Value.x = velocity.Limit.x;
      }
      if (velocity.Value.x < -velocity.Limit.x)
      {
        velocity.Value.x = -velocity.Limit.x;
      }
      if (velocity.Value.y > velocity.Limit.y)
      {
        velocity.Value.y = velocity.Limit.y;
      }
      if (velocity.Value.y < -velocity.Limit.y)
      {
        velocity.Value.y = -velocity.Limit.y;
      }

      position.Value += velocity.Value * dt;
    });
  }
};