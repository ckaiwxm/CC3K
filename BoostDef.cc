#include "BoostDef.h"
#include "Player.h"
#include "Tile.h"
#include <iostream>
#include <string>

using namespace std;

//Ctor
BoostDef::BoostDef(Tile* tile):
Potion("BD", tile) {}

BoostDef::~BoostDef() {}

// usePotion(Shade* s) add 5 def to s
void BoostDef::usePotion(Shade* s) {
  s->setDef(s->getDef() + 5 );
  tile->objectDestroy();
}

// usePotion(Goblin* g): add 5 def to g
void BoostDef::usePotion(Goblin* g) {
  g->setDef(g->getDef() + 5 );
  tile->objectDestroy();
}

// usePotion(Vampire* v) add 5 def to v
void BoostDef::usePotion(Vampire* v){
  dynamic_cast<Character*>(v)
    ->setDef(dynamic_cast<Character*>(v)
             ->getDef()+ 5 );
  tile->objectDestroy();
}


// usePotion(Drow* d) add 7.5 def to d
void BoostDef::usePotion(Drow* d) {
  dynamic_cast<Character*>(d)
    ->setDef(dynamic_cast<Character*>(d)
              ->getDef() + 5 * 1.5);
  tile->objectDestroy();
}


// usePotion(Troll* t) add 5 def to t and add 5 HP to t
// with maximum 120
void BoostDef::usePotion(Troll* t) {
  dynamic_cast<Character*>(t)
    ->setDef(dynamic_cast<Character*>(t)
             ->getDef() + 5 );
  double tmp = dynamic_cast<Character*>(t)->getHp() + 5;
  if (tmp >= 120) {
    dynamic_cast<Character*>(t)->setHp(120);
  }
  else {
    dynamic_cast<Character*>(t)->setHp(tmp);
  }
  tile->objectDestroy();
}

