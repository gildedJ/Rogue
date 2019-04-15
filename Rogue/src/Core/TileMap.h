#pragma once

#include <Simpleton\Grid\grid.hpp>

enum class TileType {
  Empty,
  Wall,
  Floor,
  Door
};

using TileMap = Grid::Grid<TileType>;


TileMap loadMap(const char* filename);