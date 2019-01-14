#ifndef _DRAGONHOARD_H_
#define _DRAGONHOARD_H_

#include "Gold.h"

class DragonHoard:public Gold {
  bool dragonDead = false;
public:
  DragonHoard(Tile* tile);
  ~DragonHoard();
  
  bool getDragonDead();
  void setDragonDead();
};

#endif
