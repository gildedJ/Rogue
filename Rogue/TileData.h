#pragma once

class TileFlags {
public:
  static const unsigned int None = 0;
  static const unsigned int Blocks_Movement = 1;
  static const unsigned int Blocks_Sight = 2;
};

struct TileData {
  unsigned int Value;
};