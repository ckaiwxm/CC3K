#ifndef _SPACE_H_
#define _SPACE_H_
#include "Tile.h"
#include <iostream>

class Space:public Tile {
public:
  // Big 5
  Space(int col, int row, Floor* floor);
  ~Space();
};

#endif

