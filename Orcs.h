#ifndef _ORCS_H_
#define _ORCS_H_
#include "Enemy.h"

class Orcs:public Enemy {  
public:
  Orcs(Tile* tile);
  ~Orcs();
  
  void attackWho(Goblin *g, double multi = 1.50) override;
  void attackWho(Troll* t, double multi = 1) override;
  void attackWho(Shade* s, double multi = 1) override;
  void attackWho(Vampire* v,double multi = 1) override;
  void attackWho(Drow* d,double multi = 1) override;
  
  void attackBy(Player* player) override;
};

#endif
