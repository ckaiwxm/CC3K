#include <string>
#include "Object.h"

using namespace std;

// Big 5
Object::Object(std::string name, Tile* tile):
name{name}, tile{tile} {
  hasMoved = false;
}

Object::~Object() {}

// Get field

// getTile() returns a pointer to tile of this object
Tile* Object::getTile(){
  return this->tile;
}

// getName() returns name of this object
string Object::getName() const {
  return name;
}

// getHasMoved() returns hasMoved of this object
bool Object::getHasMoved() const {
  return hasMoved;
}

// Set field
// setTile(newTile) sets tile of this object to newTile
void Object::setTile(Tile* newTile) {
  this->tile = newTile;
}

// setHasMoved(newHasMoved) sets hasMoved to new HasMoved
void Object::setHasMoved(bool newHasMoved) {
  hasMoved = newHasMoved;
}
