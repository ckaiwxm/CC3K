#include "RestoreHP.h"
#include "Player.h"
#include "Tile.h"
#include <iostream>
#include <string>

using namespace std;

//Ctor
RestoreHP::RestoreHP(Tile* tile):
Potion("RH", tile) {}

RestoreHP::~RestoreHP() {}

// usePotion(s) restores 10 HP for s with maximum HP of s
void RestoreHP::usePotion(Shade* s) {
  double tmp = s->getHp() + 10;
  double max = Potion::maxHp(s);
  if (max == -1) { // Vampire, just in case
    s->setHp(tmp);
  } else {
    if (tmp <= max) { // Other
      s->setHp(tmp);
    } else {
      s->setHp(max);
    }
    tile->objectDestroy();
  }
}


// usePotion(g) restores 10 HP for g with maximum HP of g
void RestoreHP::usePotion(Goblin* g) {
  double tmp = g->getHp() + 10;
  double max = Potion::maxHp(g);
  if (max == -1) { // Vampire, just in case
    g->setHp(tmp);
  } else {
    if (tmp <= max) { // Other
      g->setHp(tmp);
    } else {
      g->setHp(max);
    }
    tile->objectDestroy();
  }
}


//usePotion(v) restores 10 HP for v
void RestoreHP::usePotion(Vampire* v) {
  dynamic_cast<Character*>(v)->setHp(dynamic_cast<Character*>(v)->getHp() + 10);
  tile->objectDestroy();
}


//usePotion(d) restores 15 HP to d with maximum 150
void RestoreHP::usePotion(Drow* d){
  double tmp = dynamic_cast<Character*>(d)->getHp() + 10 * 1.5;
  if (tmp <= 150) {
    dynamic_cast<Character*>(d)->setHp(tmp);
  }
  else {
    dynamic_cast<Character*>(d)->setHp(150);
  }
  tile->objectDestroy();
}


//usePotion(t) restores 15 HP for t until
//             reaches a maximum hp of 120
void RestoreHP::usePotion(Troll* t) {
  double tmp = dynamic_cast<Character*>(t)->getHp() + 10 + 5;
  if (tmp <= 120) {
    dynamic_cast<Character*>(t)->setHp(tmp);
  }
  else {
    dynamic_cast<Character*>(t)->setHp(120);
  }
  tile->objectDestroy(); 
}


