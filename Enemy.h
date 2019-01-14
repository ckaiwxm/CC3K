#ifndef Enemy_H
#define Enemy_H
#include <iostream>
#include <string>
#include "Character.h"
class Tile;
class Player;

class Shade;
class Drow;
class Troll;
class Vampire;
class Goblin;


class Enemy:public Character {
protected:
  bool isNearPc(Player *p);
  double moreDamage(Player* defender, double multi);
  void attackWhoCore(Player* player,double multi = 1); //
  
public:
  Enemy(double hp, double atk, double def, std::string name, Tile* tile);
  virtual ~Enemy() = 0;
  void enemyMove(Player *p, bool ifFreeze);
  
  // Attack
  virtual void attackWho(Goblin* g, double multi = 1) = 0;
  virtual void attackWho(Troll* t, double multi = 1) = 0;
  virtual void attackWho(Shade* s, double multi = 1) = 0;
  virtual void attackWho(Vampire* v,double multi = 1) = 0;
  virtual void attackWho(Drow* d,double multi = 1) = 0;
  
  virtual void attackBy(Player* player) = 0;
  
};

#endif
