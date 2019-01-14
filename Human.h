#ifndef Human_h
#define Human_h
#include "Enemy.h"

class Human: public Enemy {
public:
  Human(Tile* tile);
  ~Human();
  
  void attackWho(Goblin* g, double multi = 1) override;
  void attackWho(Troll* t, double multi = 1) override;
  void attackWho(Shade* s, double multi = 1) override;
  void attackWho(Vampire* v,double multi = 1) override;
  void attackWho(Drow* d,double multi = 1) override;
  
  void attackBy(Player* player) override;
};

#endif
