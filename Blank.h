#ifndef _BLANK_H_
#define _BLANK_H_
#include "Tile.h"
#include <iostream>

class Blank:public Tile {
public:
  // Big 5
  Blank(int col, int row, Floor* floor);
  ~Blank();
};

#endif
