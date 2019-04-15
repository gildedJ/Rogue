#include "factories.h"

#include "../Components/Position.h"
#include "../Components/TileMapCoords.h"
#include "../Components/TileData.h"
#include "../Components/Sprite.h"
#include "../Components/Velocity.h"
#include "../Components/Acceleration.h"
#include "../Components/Player.h"
#include "../Components/Enemy.h"



Entity makePlayer(EntityManager &entityManager, Vector2 tilePos)
{
  Entity player = entityManager.create();
  entityManager.assign<TileMapCoords>(player, tilePos);
  entityManager.assign<Position>(player, Vector2{ 0.0f, 0.0f });
  entityManager.assign<Sprite>(player, Vector2{ 2.0f, -16.0f }, Vector2{ 28.0f, 48.0f }, Color{ 0.35f, 0.8f, 0.3f, 1.0f });
  entityManager.assign<Velocity>(player, Vector2{ 0.0f, 0.0f }, Vector2{ 200.0f, 200.0f });
  entityManager.assign<Acceleration>(player, Vector2{ 0.0f, 0.0f });
  entityManager.assign<Player>(player);
  return player;
}


Entity makeEnemy(EntityManager& entityManager, Vector2 tilePos)
{
  Entity enemy = entityManager.create();
  entityManager.assign<TileMapCoords>(enemy, tilePos);
  entityManager.assign<Position>(enemy, Vector2{ 0.0f, 0.0f });
  entityManager.assign<Sprite>(enemy, Vector2{ 2.0f, -16.0f }, Vector2{ 28.0f, 48.0f }, Color{ 0.8f, 0.35f, 0.2f, 1.0f });
  entityManager.assign<Velocity>(enemy, Vector2{ 0.0f, 0.0f }, Vector2{ 150.0f, 150.0f });
  entityManager.assign<Acceleration>(enemy, Vector2{ 0.0f, 0.0f });
  entityManager.assign<Enemy>(enemy);
  return enemy;
}

Entity makeFloor(EntityManager& entityManager, Vector2 tilePos)
{
  Entity tile = entityManager.create();
  entityManager.assign<TileMapCoords>(tile, tilePos);
  entityManager.assign<TileData>(tile, TileFlags::None);
  entityManager.assign<Sprite>(tile, Vector2{ 0.0f, 0.0f }, Vector2{ 32.0f, 32.0f }, Color{ 0.8f, 0.8f, 0.8f, 1.0f });
  return tile;
}


Entity makeWall(EntityManager& entityManager, Vector2 tilePos)
{
  Entity tile = entityManager.create();
  entityManager.assign<TileMapCoords>(tile, tilePos);
  entityManager.assign<TileData>(tile, TileFlags::Blocks_Movement | TileFlags::Blocks_Sight);
  entityManager.assign<Sprite>(tile, Vector2{ 0.0f, 0.0f }, Vector2{ 32.0f, 32.0f }, Color{ 0.3f, 0.3f, 0.3f, 1.0f });
  return tile;
}

Entity makeDoor(EntityManager& entityManager, Vector2 tilePos)
{
  Entity tile = entityManager.create();
  entityManager.assign<TileMapCoords>(tile, tilePos);
  entityManager.assign<TileData>(tile, TileFlags::Blocks_Sight);
  entityManager.assign<Sprite>(tile, Vector2{ 0.0f, 0.0f }, Vector2{ 32.0f, 32.0f }, Color{ 0.6f, 0.6f, 0.6f, 1.0f });
  return tile;
}

void makeTileMap(EntityManager& entityManager, TileMap& tileMap)
{
  for (int i = 0; i < tileMap.area(); i++)
  {
    Vector2 pos = tileMap.toPos(i);
    TileType type = tileMap[i];
    switch (type)
    {
    case TileType::Floor:
      makeFloor(entityManager, pos);
      break;
    case TileType::Wall:
      makeWall(entityManager, pos);
      break;
    case TileType::Door:
      makeDoor(entityManager, pos);
      break;
    case TileType::Empty:
    default:
      break;
    }
  }
}