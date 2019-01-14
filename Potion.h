#ifndef _POTION_H_
#define _POTION_H_
#include <iostream>
#include "Object.h"
#include "Character.h"
#include "Player.h"
#include "Vampire.h"
#include "Drow.h"
#include "Shade.h"
#include "Troll.h"
#include "Goblin.h"
class Tile;
class Character;

class Potion:public Object {
public:
  Potion(std::string name, Tile *tile);
  virtual ~Potion() = 0;  // Dtor
  
  double maxHp(Character *p);
  
  virtual void usePotion(Shade* s) = 0;
  virtual void usePotion(Goblin* g) = 0;
  virtual void usePotion(Drow* d) = 0;
  virtual void usePotion(Vampire* v) = 0;
  virtual void usePotion(Troll* t) = 0;
};

#endif
