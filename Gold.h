#ifndef _GOLD_H_
#define _GOLD_H_

#include <iostream>
#include "Object.h"
class Player;
class Tile;

class Gold:public Object {
protected:
  double value;
  
public:
  // Big 5
  Gold(double value, Tile* tile);
  virtual ~Gold() = 0;
  
  // Get field
  double getValue();
  
  // Action
  void pickGold(Player* player);
};

#endif
