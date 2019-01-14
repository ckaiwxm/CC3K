#ifndef Dragon_h
#define Dragon_h
#include "Enemy.h"
class DragonHoard;
class Player;

class Dragon: public Enemy {
    Tile* dh;
private:
  bool isNearDh(Player* p);
  
public:
  Dragon(Tile* tile, Tile* dh);
  ~Dragon();
  
  // Attack
  void attackWho(Goblin* g, double multi = 1) override;
  void attackWho(Troll* t, double multi = 1) override;
  void attackWho(Shade* s, double multi = 1) override;
  void attackWho(Vampire* v,double multi = 1) override;
  void attackWho(Drow* d,double multi = 1) override;
  
  void attackBy(Player* player) override;

  DragonHoard* getDragonHoard();
};

#endif
