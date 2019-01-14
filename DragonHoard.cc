#include "DragonHoard.h"
#include "Tile.h"
#include "Player.h"

//Ctor
DragonHoard::DragonHoard(Tile* tile):
Gold(6, tile) {
  name = "DH";
  dragonDead = false;
}

DragonHoard::~DragonHoard() {}

// getDragonDead() returns the state of dragonDead
bool DragonHoard::getDragonDead(){
  return dragonDead;
}

// setDragonDead() sets dragonDead to true
void DragonHoard::setDragonDead() {
  dragonDead = true;
}
