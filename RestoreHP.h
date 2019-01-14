#ifndef _RESTOREHP_H_
#define _RESTOREHP_H_

#include "Potion.h"

class RestoreHP:public Potion{
public:
  RestoreHP(Tile* tile);
  ~RestoreHP();
  
  void usePotion(Shade* s) override;
  void usePotion(Goblin* g) override;
  void usePotion(Vampire* v) override;
  void usePotion(Drow* d) override;
  void usePotion(Troll* t) override;
};

#endif
