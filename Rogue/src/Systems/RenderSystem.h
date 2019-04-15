#pragma once

#include "SDL.h"
#include "../Util/ECS.h"

#include "../Components/TileMapCoords.h"
#include "../Components/TileData.h"
#include "../Components/Player.h"
#include "../Components/Enemy.h"
#include "../Components/Position.h"
#include "../Components/Sprite.h"

#include "TileMap.h"

static const float tileSize = 32.0f;
static const float scale = 2.0f;

namespace RenderSystem {

  void DrawSprite(SDL_Renderer* renderer, Sprite& sprite, Vector2& position)
  {
    SDL_Rect fillRect = { position.x, position.y, sprite.Size.x * scale, sprite.Size.y * scale };
    SDL_SetRenderDrawColor(renderer, sprite.Color.r * 255, sprite.Color.g * 255, sprite.Color.b * 255, sprite.Color.a * 255);
    SDL_RenderFillRect(renderer, &fillRect);
  }

  void DrawTileMap(EntityManager& entityManager, SDL_Renderer* renderer)
  {
    auto tiles = entityManager.view<TileMapCoords, TileData, Sprite>();
    for (Entity tile : tiles)
    {
      TileMapCoords& coords = entityManager.get<TileMapCoords>(tile);
      Sprite& sprite = entityManager.get<Sprite>(tile);

      Vector2 drawPos = Vector2{ sprite.Offset.x + coords.Value.x * tileSize * scale, sprite.Offset.y + coords.Value.y * tileSize * scale };
      DrawSprite(renderer, sprite, drawPos);
    }
  }

  void DrawPlayers(EntityManager& entityManager, SDL_Renderer* renderer)
  {
    auto players = entityManager.view<TileMapCoords, Player, Position, Sprite>();
    for (Entity player : players)
    {
      TileMapCoords& coords = entityManager.get<TileMapCoords>(player);
      Position& position = entityManager.get<Position>(player);
      Sprite& sprite = entityManager.get<Sprite>(player);

      Vector2 drawPos = Vector2{ position.Value.x + sprite.Offset.x + coords.Value.x * tileSize * scale, position.Value.y + sprite.Offset.y + coords.Value.y * tileSize * scale };
      DrawSprite(renderer, sprite, drawPos);
    }
  }
  
  void DrawEnemies(EntityManager& entityManager, SDL_Renderer* renderer)
  {
    auto enemies = entityManager.view<TileMapCoords, Enemy, Position, Sprite>();
    for (Entity enemy : enemies)
    {
      TileMapCoords& coords = entityManager.get<TileMapCoords>(enemy);
      Position& position = entityManager.get<Position>(enemy);
      Sprite& sprite = entityManager.get<Sprite>(enemy);

      Vector2 drawPos = Vector2{ position.Value.x + sprite.Offset.x + coords.Value.x * tileSize * scale, position.Value.y + sprite.Offset.y + coords.Value.y * tileSize * scale };
      DrawSprite(renderer, sprite, drawPos);
    }
  }

};