#include "WoundAtk.h"
#include "Player.h"
#include "Tile.h"
#include <iostream>
#include <string>

using namespace std;

//Ctor
WoundAtk::WoundAtk(Tile* tile):
Potion("WA", tile) {}

WoundAtk::~WoundAtk() {}

// usePotion(s) deducts 5 atk from s until reaches 0
void WoundAtk::usePotion(Shade* s) {
  double tmp = s->getAtk() - 5;
  if (tmp <= 0) {
    s->setAtk(0);
  }
  else {
    s->setAtk(tmp);
  }
  tile->objectDestroy();
}

// usePotion(g) deducts 5 atk from g until reaches 0
void WoundAtk::usePotion(Goblin* g) {
  double tmp = g->getAtk() - 5;
  if (tmp <= 0) {
    g->setAtk(0);
  }
  else {
    g->setAtk(tmp);
  }
  tile->objectDestroy();
}


// usePotion(v) deducts 5 atk from v until reaches 0
void WoundAtk::usePotion(Vampire* v) {
  double tmp = dynamic_cast<Character*>(v)->getAtk() - 5;
  if (tmp <= 0) {
    dynamic_cast<Character*>(v)->setAtk(0);
  }
  else {
    dynamic_cast<Character*>(v)->setAtk(tmp);
  }
  tile->objectDestroy();
}


// usePotion(d) deducts 7.5 atk from d with minimum 0
void WoundAtk::usePotion(Drow* d) {
  double tmp = dynamic_cast<Character*>(d)->getAtk() - 5 * 1.5;
  if (tmp <= 0) {
    dynamic_cast<Character*>(d)->setAtk(0);
  }
  else {
    dynamic_cast<Character*>(d)->setAtk(tmp);
  }
  tile->objectDestroy();
}


//usePotion(t) deducts 5 atk from t with minimum 0 and add 5
//              HP to t with maximum 120
void WoundAtk::usePotion(Troll* t) {
  double tmp = dynamic_cast<Character*>(t)->getAtk() - 5;
  if (tmp <= 0) {
    dynamic_cast<Character*>(t)->setAtk(0);
  }
  else {
    dynamic_cast<Character*>(t)->setAtk(tmp);
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


