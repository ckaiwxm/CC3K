#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "Elf.h"
#include "Floor.h"

using namespace std;

Elf::Elf(Tile* tile):
Enemy(140, 30, 10, "Elf", tile) {}

Elf::~Elf() {}

// attackWho(g, multi) lets this attack g
void Elf::attackWho(Goblin* g, double multi) {
  (void) multi;
  attackWhoCore(g,1);
  attackWhoCore(g,1);
}

// attackWho(t, multi) lets this attack t
void Elf::attackWho(Troll* t, double multi) {
  (void) multi;
  attackWhoCore(t,1);
}

// attackWho(s, multi) lets this attack s
void Elf::attackWho(Shade* s, double multi) {
  (void) multi;
  attackWhoCore(s,1);
  attackWhoCore(s,1);
}

// attackWho(v, multi) lets this attack v
void Elf::attackWho(Vampire* v,double multi) {
  (void) multi;
  attackWhoCore(v,1);
  attackWhoCore(v,1);
}

// attackWho(d, multi) lets this attack d
void Elf::attackWho(Drow* d,double multi) {
  (void) multi;
  attackWhoCore(d,1);
  attackWhoCore(d,1);
}

// attackBy(player) lets this attacked by player
void Elf::attackBy(Player* player){
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
