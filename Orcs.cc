#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "Orcs.h"
#include "Goblin.h"
#include "Floor.h"
#include "TextDisplay.h"

using namespace std;

Orcs::Orcs(Tile* tile):
Enemy(180, 30, 25, "Orcs", tile) {}

Orcs::~Orcs() {}

// attackWho(g, multi) lets this attack g
void Orcs::attackWho(Goblin *g, double multi) {
  (void) multi;
  attackWhoCore(g, 1.50);
}

// attackWho(t, multi) lets this attack t
void Orcs::attackWho(Troll* t, double multi) {
  (void) multi;
  attackWhoCore(t,1);
}

// attackWho(s, multi) lets this attack s
void Orcs::attackWho(Shade* s, double multi) {
  (void) multi;
  attackWhoCore(s,1);
}

// attackWho(v, multi) lets this attack v
void Orcs::attackWho(Vampire* v,double multi) {
  (void) multi;
  attackWhoCore(v,1);
}

// attackWho(d, multi) lets this attack d
void Orcs::attackWho(Drow* d,double multi) {
  (void) multi;
  attackWhoCore(d,1);
}

// attackBy(player) lets this attacked by player
void Orcs::attackBy(Player* player){
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

