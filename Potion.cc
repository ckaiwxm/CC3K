#include "Potion.h"
#include "Tile.h"

using namespace std;

//Ctor
Potion::Potion(std::string name, Tile *tile):
Object(name, tile) {}

Potion::~Potion() {}

// maxHp(p) returns the maximum HP of p
double Potion::maxHp(Character *p) {
  string player = p->getName();
  if (player == "Shade") {
    return 125;
  } else if (player == "Drow") {
    return 150;
  } else if (player == "Troll") {
    return 120;
  } else if (player == "Goblin") {
    return 110;
  } else {
    return -1;
  }
}
