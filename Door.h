#ifndef _DOOR_H_
#define _DOOR_H_
#include "Tile.h"
#include <iostream>

class Door:public Tile {
public:
  // Big 5
  Door(int col, int row, Floor* floor);
  ~Door();
};

#endif
