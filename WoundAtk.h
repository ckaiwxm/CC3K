#ifndef _WOUNDATK_H_
#define _WOUNDATK_H_

#include "Potion.h"

class WoundAtk: public Potion{
public:
  WoundAtk(Tile* tile);
  ~WoundAtk();
  
  void usePotion(Shade* s) override;
  void usePotion(Goblin* g) override;
  void usePotion(Vampire* v) override;
  void usePotion(Drow* d) override;
  void usePotion(Troll* t) override;
};

#endif
