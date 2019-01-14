#ifndef Merchant_h
#define Merchant_h
#include "Enemy.h"
class Player;
class Floor;

class Merchant: public Enemy {
public:
  Merchant(Tile* tile);
  ~Merchant();
  
  static bool isMerchantAngry;
  
  void attackWho(Goblin* g, double multi = 1) override;
  void attackWho(Troll* t, double multi = 1) override;
  void attackWho(Shade* s, double multi = 1) override;
  void attackWho(Vampire* v,double multi = 1) override;
  void attackWho(Drow* d,double multi = 1) override;
  
  void attackBy(Player* player) override;
};


#endif
