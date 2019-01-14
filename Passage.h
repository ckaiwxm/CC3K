#ifndef _PASSAGE_H_
#define _PASSAGE_H_
#include "Tile.h"
#include <iostream>

class Passage:public Tile {
public:
  // Big 5
  Passage(int col, int row, Floor* floor);
  ~Passage();
};

#endif
