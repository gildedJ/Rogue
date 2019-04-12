#pragma once

#include "SDL.h"
#include "entt\entity\registry.hpp"

#include "Position.h"
#include "Sprite.h"


class RenderSystem {
public:
  static void Update(entt::registry& entityManager, SDL_Renderer* renderer)
  {
    entityManager.view<Position, Sprite>().each([renderer](auto& position, auto& sprite) {
      SDL_Rect fillRect = { position.Value.X + sprite.Offset.X, position.Value.Y + sprite.Offset.Y, sprite.Size.Width, sprite.Size.Height };
      SDL_SetRenderDrawColor(renderer, sprite.Color.Red * 255, sprite.Color.Green * 255, sprite.Color.Blue * 255, sprite.Color.Alpha * 255);
      SDL_RenderFillRect(renderer, &fillRect);
    });
  }
};