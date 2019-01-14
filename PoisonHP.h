#ifndef _POISONHP_H_
#define _POISONHP_H_

#include "Potion.h"

class PoisonHP: public Potion{
public:
  PoisonHP(Tile* tile);
  ~PoisonHP();
  
  void usePotion(Shade* s) override;
  void usePotion(Goblin* g) override;
  void usePotion(Vampire* v) override;
  void usePotion(Drow* d) override;
  void usePotion(Troll* t) override;
};

#endif
