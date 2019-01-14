#ifndef _VWALL_H_
#define _VWALL_H_
#include "Tile.h"
#include <iostream>

class VWall:public Tile {
public:
  // Big 5
  VWall(int col, int row, Floor* floor);
  ~VWall();
};

#endif
