#pragma once

#include "SDL.h"

#include "Vector.h"

struct Sprite {
  Vector2 Offset;
  Dimension Size;
  Color Color;
};
