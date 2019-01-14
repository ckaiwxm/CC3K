#ifndef _STAIR_H_
#define _STAIR_H_

#include "Object.h"

class Object;
class Tile;

class Stair:public Object {
  
public:
  Stair(Tile* tile);
  ~Stair();
};

#endif
