#include "Gold.h"
#include "Tile.h"
#include "Player.h"

using namespace std;

// Ctor
Gold::Gold(double value, Tile* tile):
Object("G", tile) {
  this->value = value;
}

// Dtor
Gold::~Gold(){}

// getValue() returns this value
double Gold::getValue() {
  return value;
}

// pickGold(player) allows player pick gold
void Gold::pickGold(Player* player) {
  player->setGold(player->getGold() + this->value);
  tile->objectDestroy();
}
