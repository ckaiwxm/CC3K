#ifndef _HWALL_H_
#define _HWALL_H_
#include "Tile.h"
#include <iostream>

class HWall:public Tile {
public:
  // Big 5
  HWall(int col, int row, Floor* floor);
  ~HWall();
};

#endif

