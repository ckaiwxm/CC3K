#ifndef _BOOSTDEF_H_
#define _BOOSTDEF_H_

#include "Potion.h"

class BoostDef: public Potion {
public:
  BoostDef(Tile* tile);
  ~BoostDef();
  
  void usePotion(Shade* s) override;
  void usePotion(Goblin* g) override;
  void usePotion(Vampire* v) override;
  void usePotion(Drow* d) override;
  void usePotion(Troll* t) override;
};

#endif
