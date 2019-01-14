#include "BoostAtk.h"
#include "Player.h"
#include "Tile.h"
#include <iostream>
#include <string>

using namespace std;

//Ctor
BoostAtk::BoostAtk(Tile* tile):
Potion("BA", tile) {}

BoostAtk::~BoostAtk() {}

// usePotion(s) add 5 atk to p
void BoostAtk::usePotion(Shade* s) {
  s->setAtk(s->getAtk() + 5 );
  tile->objectDestroy();
}

// usePotion(g) add 5 atk to g
void BoostAtk::usePotion(Goblin* g) {
  g->setAtk(g->getAtk() + 5 );
  tile->objectDestroy();
}

// usePotion(v) add 5 atk to v
void BoostAtk::usePotion(Vampire* v){
  dynamic_cast<Character*>(v)->setAtk(dynamic_cast<Character*>(v)->getAtk()
                                      + 5 );
  tile->objectDestroy();
}


// usePotion(d) add 7.5 atk to d
void BoostAtk::usePotion(Drow* d) {
  dynamic_cast<Character*>(d)->setAtk(dynamic_cast<Character*>(d)->getAtk()
                                      + 5 * 1.5);
  tile->objectDestroy();
}

// usePotion(d) add 5 atk to t and add 5 Hp to t
//                     until reaches a maximum hp of 120
void BoostAtk::usePotion(Troll* t) {
   dynamic_cast<Character*>(t)->setAtk(dynamic_cast<Character*>(t)->getAtk()
                                       + 5 );
  double tmp = dynamic_cast<Character*>(t)->getHp() + 5;
  if (tmp >= 120) {
    dynamic_cast<Character*>(t)->setHp(120);
  }
  else {
    dynamic_cast<Character*>(t)->setHp(tmp);
  }
  tile->objectDestroy();
}

