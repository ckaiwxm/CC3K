#ifndef _WOUNDDef_H_
#define _WOUNDDef_H_

#include "Potion.h"

class WoundDef: public Potion{
public:
  WoundDef(Tile* tile);
  ~WoundDef();
  
  void usePotion(Shade* s) override;
  void usePotion(Goblin* g) override;
  void usePotion(Vampire* v) override;
  void usePotion(Drow* d) override;
  void usePotion(Troll* t) override;
};

#endif
