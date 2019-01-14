#include "Character.h"
#include <cmath>
#include <iostream>
#include <string>
#include <memory>

// Base
#include "Player.h"
#include "Enemy.h"
#include "Tile.h"
#include "Floor.h"
#include "TextDisplay.h"

// Player
#include "Shade.h"
#include "Drow.h"
#include "Player.h"
#include "Troll.h"
#include "Vampire.h"
#include "Goblin.h"

// Enemy
#include "Human.h"
#include "Dwarf.h"
#include "Elf.h"
#include "Orcs.h"
#include "Merchant.h"
#include "Dragon.h"
#include "Halfling.h"

// Object
#include "DragonHoard.h"

using namespace std;

// Big 5
Character::Character(double hp, double atk, double def, std::string name, Tile* tile):
Object(name, tile) {
  this->hp = hp;
  this->atk = atk;
  this->def = def;
}

Character::~Character() {}

// Get fields
// getHp() gets this hp
double Character::getHp() const {
  return hp;
}

// getAtk() gets this atk
double Character::getAtk() const {
  return atk;
}

// getDef() gets this def
double Character::getDef() const {
  return def;
}

// isAlive() determines if this is alive
bool Character::isAlive() const {
  if (getHp() <= 0) {
    return false;
  } else {
    return true;
  }
}

// Set fields
// setHp(newHp) sets this hp to newHp
void Character::setHp(double newHp) {
  hp = newHp;
}

// setAtk(newAtk) sets this atk to newAtk
void Character::setAtk(double newAtk) {
  atk = newAtk;
}

// setDef(newDef) sets this def to newDef
void Character::setDef(double newDef) {
  def = newDef;
}
