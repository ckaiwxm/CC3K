#include "WoundDef.h"
#include "Player.h"
#include "Tile.h"
#include <iostream>
#include <string>

using namespace std;

//Ctor
WoundDef::WoundDef(Tile* tile):
Potion("WD", tile) {}

WoundDef::~WoundDef() {}

// usePotion(s) deducts 5 def from s until reaches 0
void WoundDef::usePotion(Shade* s) {
  double tmp = s->getDef() - 5;
  if (tmp <= 0) {
    s->setDef(0);
  }
  else {
    s->setDef(tmp);
  }
  tile->objectDestroy();
}

// usePotion(g) deducts 5 def from g until reaches 0
void WoundDef::usePotion(Goblin* g) {
  double tmp = g->getDef() - 5;
  if (tmp <= 0) {
    g->setDef(0);
  }
  else {
    g->setDef(tmp);
  }
  tile->objectDestroy();
}


// usePotion(v) deducts 5 def from v until reaches 0
void WoundDef::usePotion(Vampire* v) {
  double tmp = dynamic_cast<Character*>(v)->getDef() - 5;
  if (tmp <= 0) {
    dynamic_cast<Character*>(v)->setDef(0);
  }
  else {
    dynamic_cast<Character*>(v)->setDef(tmp);
  }
  tile->objectDestroy();
}


// usePotion(d) deducts 7.5 def from d with minimum 0
void WoundDef::usePotion(Drow* d) {
  double tmp = dynamic_cast<Character*>(d)->getDef() - 5 * 1.5;
  if (tmp <= 0) {
    dynamic_cast<Character*>(d)->setDef(0);
  }
  else {
    dynamic_cast<Character*>(d)->setDef(tmp);
  }
  tile->objectDestroy();
}


// usePotion(t) deducts 5 def from t with minimum 0 HP and
//              add 5 HP to t with maximum 120
void WoundDef::usePotion(Troll* t) {
  double tmp = dynamic_cast<Character*>(t)->getDef() - 5;
  if (tmp <= 0) {
    dynamic_cast<Character*>(t)->setDef(0);
  }
  else {
    dynamic_cast<Character*>(t)->setDef(tmp);
  }
  double tmp2 = dynamic_cast<Character*>(t)->getHp() + 5;
  if (tmp2 >= 120) {
    dynamic_cast<Character*>(t)->setHp(120);
  }
  else {
    dynamic_cast<Character*>(t)->setHp(tmp2);
  }
  tile->objectDestroy();
}

