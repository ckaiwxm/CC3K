#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "Dragon.h"
#include "DragonHoard.h"
#include "Player.h"
#include "Floor.h"

using namespace std;

Dragon::Dragon(Tile* tile, Tile* dh):
Enemy(150, 20, 20, "Dragon", tile) {
  this->dh = dh;
}

Dragon::~Dragon() {}

// isNearDh(p) determines if p is within
//             one block radius
bool Dragon::isNearDh(Player *p) {
  int PcCol = p->getTile()->getCol();
  int PcRow = p->getTile()->getRow();
  int DhCol = dh->getCol();
  int DhRow = dh->getRow();
  if ((abs(PcCol - DhCol) > 1) ||
      (abs(PcRow - DhRow) > 1)) {
    return false;
  } else {
    return true;
  }
}

// attackWho(g, multi) attacks g
void Dragon::attackWho(Goblin* g, double multi) {
  (void) multi;
  if (isNearDh(g) == true ||
      isNearPc(g)) { // PC near dragon hoard
    attackWhoCore(g);
  }
}

// attackWho(t, multi) attacks t
void Dragon::attackWho(Troll* t, double multi) {
  (void) multi;
  if (isNearDh(t) == true ||
      isNearPc(t)) { // PC near dragon hoard
    attackWhoCore(t);
  }
}

// attackWho(s, multi) attacks s
void Dragon::attackWho(Shade* s, double multi) {
  (void) multi;
  if (isNearDh(s) == true ||
      isNearPc(s)) { // PC near dragon hoard
    attackWhoCore(s);
  }
}

// attackWho(v, multi) attacks v
void Dragon::attackWho(Vampire* v,double multi) {
  (void) multi;
  if (isNearDh(v) == true ||
      isNearPc(v)) { // PC near dragon hoard
    attackWhoCore(v);
  }
}

// attackWho(d, multi) attacks d
void Dragon::attackWho(Drow* d,double multi) {
  (void) multi;
  if (isNearDh(d) == true ||
      isNearPc(d)) { // PC near dragon hoard
    attackWhoCore(d);
  }
}

// getDragonHoard() gets this dragonhoard
DragonHoard* Dragon::getDragonHoard() {
  return dynamic_cast<DragonHoard*>(dh->getObject());
}

// attackBy(player) attacked by player
void Dragon::attackBy(Player* player) {
  if (player->getName() == "Shade") {
    attackWho(dynamic_cast<Shade*>(player));
  }
  else if (player->getName() == "Vampire") {
    attackWho(dynamic_cast<Vampire*>(player));
  }
  else if (player->getName() == "Troll") {
    attackWho(dynamic_cast<Troll*>(player));
  }
  else if (player->getName() == "Drow") {
    attackWho(dynamic_cast<Drow*>(player));
  }
  else if (player->getName() == "Goblin") {
    attackWho(dynamic_cast<Goblin*>(player));
  }
}
