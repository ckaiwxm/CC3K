#include "PoisonHP.h"
#include "Player.h"
#include "Tile.h"
#include <iostream>
#include <string>

using namespace std;

//Ctor
PoisonHP::PoisonHP(Tile* tile):
Potion("PH", tile) {}

PoisonHP::~PoisonHP() {}


// usePotion(s) deducts 10 HP from p until
//             reaches a minimum hp of 0
void PoisonHP::usePotion(Shade* s) {
  double tmp = s->getHp() - 10;
  if (tmp <= 0) {
    s->setHp(0);
  }
  else {
    s->setHp(tmp);
  }
  tile->objectDestroy();
}

// usePotion(g) lets g use this potion
void PoisonHP::usePotion(Goblin* g) {
  double tmp = g->getHp() - 10;
  if (tmp <= 0) {
    g->setHp(0);
  }
  else {
    g->setHp(tmp);
  }
  tile->objectDestroy();
}


// usePotion(v) deducts 10 HP from p until
//             reaches a minimum hp of 0
void PoisonHP::usePotion(Vampire* v) {
  double tmp = dynamic_cast<Character*>(v)->getHp() - 10;
  if (tmp <= 0) {
    dynamic_cast<Character*>(v)->setHp(0);
  }
  else {
     dynamic_cast<Character*>(v)->setHp(tmp);
  }
  tile->objectDestroy();
}


//usePotion(d) deducts 15 HP from d with until
//             reaches a minimum hp of 0
void PoisonHP::usePotion(Drow* d){
  double tmp = dynamic_cast<Character*>(d)->getHp() - 10 * 1.5;
  if (tmp <= 0) {
    dynamic_cast<Character*>(d)->setHp(0);
  }
  else {
    dynamic_cast<Character*>(d)->setHp(tmp);
  }
  tile->objectDestroy();
}


//usePotion(t) deducts 5 HP from t until
//             reaches a minimum hp of 0
void PoisonHP::usePotion(Troll* t) {
  double tmp = dynamic_cast<Character*>(t)->getHp() - 10 + 5;
  if (tmp <= 0) {
    dynamic_cast<Character*>(t)->setHp(0);
  }
  else {
    dynamic_cast<Character*>(t)->setHp(tmp);
  }
  tile->objectDestroy();
}

