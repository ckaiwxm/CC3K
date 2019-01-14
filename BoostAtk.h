#ifndef _BOOSTATK_H_
#define _BOOSTATK_H_

#include "Potion.h"

class BoostAtk: public Potion{
public:
  BoostAtk(Tile* tile);
  ~BoostAtk();
  
  void usePotion(Shade* s) override;
  void usePotion(Goblin* g) override;
  void usePotion(Vampire* v) override;
  void usePotion(Drow* d) override;
  void usePotion(Troll* t) override;
};

#endif
