#pragma once

#include "../Util/ECS.h"
#include "../Util/Vector.h"
#include "TileMap.h"

Entity makePlayer(EntityManager &entityManager, Vector2 tilePos);
Entity makeEnemy(EntityManager &entityManager, Vector2 tilePos);

Entity makeFloor(EntityManager& entityManager, Vector2 tilePos);
Entity makeWall(EntityManager& entityManager, Vector2 tilePos);
Entity makeDoor(EntityManager& entityManager, Vector2 tilePos);
void makeTileMap(EntityManager& entityManager, TileMap& tileMap);