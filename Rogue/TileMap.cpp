#include "TileMap.h"

#include "fileIO.h"
#include "Vector.h"

namespace {

  TileType mapChar(const char c) {
    switch (c) {
    case ' ':
      return TileType::Empty;
    case '.':
      return TileType::Floor;
    case '#':
      return TileType::Wall;
    case '+':
      return TileType::Door;
    default:
      assert(false);
      return {};
    }
  }

  template <size_t Size>
  void mapStr(TileMap &map, const char(&str)[Size]) {
    assert(map.area() + 1 == Size);
    for (size_t i = 0; i != Size - 1; ++i) {
      map[i] = mapChar(str[i]);
    }
  }

}


TileMap loadMap(const char* filename)
{
  char* fileData = readEntireFile(filename);
  if (fileData == nullptr)
  {
    return TileMap();
  }

  // TODO parse map size
  Vector2 mapSize = { 16, 9 };
  TileMap map{ mapSize };
  // TOOD parse mapData
  const char mapData[] = {
    "#######++#######"
    "#..........##..#"
    "#....######....#"
    "#..............#"
    "...............+"
    "#.....####.....#"
    "#..#........#..#"
    "#..............#"
    "#######..#######"
  };
  mapStr(map, mapData);

  return map;
}