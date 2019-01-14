#include "Tile.h"
#include <iostream>
#include <string>

// Base
#include "Floor.h"
#include "TextDisplay.h"
#include "Object.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Gold.h"
#include "Potion.h"

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

// Gold
#include "Small.h"
#include "Normal.h"
#include "MerchantHoard.h"
#include "DragonHoard.h"

// Potion
#include "RestoreHP.h"
#include "BoostAtk.h"
#include "BoostDef.h"
#include "PoisonHP.h"
#include "WoundAtk.h"
#include "WoundDef.h"

// Stair
#include "Stair.h"

using namespace std;

// Big 5
Tile::Tile(int col, int row, Floor* floor):
col{col}, row{row}, floor{floor} {
  ob = nullptr;
}

Tile::~Tile() {}

// Get fields

// getDisplay() returs this display
char Tile::getDisplay() const {
  return display;
}

// getCol() return this col
int Tile::getCol() const {
  return col;
}

// getRow() return this row
int Tile::getRow() const {
  return row;
}

// getFloor() returns this floor
Floor* Tile::getFloor() const {
  return floor;
}

// getObject() returns this object
Object* Tile::getObject() const {
  if (ob == nullptr) {
    return nullptr;
  } else {
    return ob;
  }
}

// Set fields
// setObject(newOb) set ob to newOb
void Tile::setObject(Object* newOb) {
  ob = newOb;
  floor->notifyTextDisplay(this);
}

// objectEmpty() sets ob to nullptr
void Tile::objectEmpty() {
  ob = nullptr;
  floor->notifyTextDisplay(this);
}

// objectDestroy() deletes objects pointed by ob
void Tile::objectDestroy() {
  if (ob == nullptr) {
    return;
  } else {
    string name = ob->getName();
    if (name == "Human" || name == "Merchant") {
    delete ob;
    MerchantHoard* drop = new MerchantHoard(this);
    ob = drop;
  } else {
    delete ob;
    ob = nullptr;
  }
  floor->notifyTextDisplay(this);
  }
}

// Spawn
// spawnPlayer(p) spawns a player
void Tile::spawnPlayer(Player* p) {
  if (floor->getLevel() > 1) {
    p->setAtk(p->getOldAtk());
    p->setDef(p->getOldDef());
  }
  p->setTile(this);
  ob = p;
  floor->notifyTextDisplay(this);
  if (floor->getLevel() == 1) {
    string begin = "Player character has spawned. ";
    floor->getTextDisplay()->addAction(begin);
  }
}

// spawnStair() spawns a stair
void Tile::spawnStair() {
  Stair* s = new Stair(this);
  ob = s;
  floor->notifyTextDisplay(this);
}

// spawnEnemy(name) spawns an enemy of type
//                  implied by name
void Tile::spawnEnemy(char name) {
  if (name == 'H') {
    Human* h = new Human(this);
    ob = h;
  } else if (name == 'W') {
    Dwarf* w = new Dwarf(this);
    ob = w;
  } else if (name == 'E') {
    Elf* e = new Elf(this);
    ob = e;
  } else if (name == 'O') {
    Orcs* o = new Orcs(this);
    ob = o;
  } else if (name == 'M') {
    Merchant* m = new Merchant(this);
    ob = m;
  } else if (name == 'L') {
    Halfling* l = new Halfling(this);
    ob = l;
  }
  floor->notifyTextDisplay(this);
}

// spawnGold(name) spawns gold of type
//                  implied by name
void Tile::spawnGold(string name) {
  if (name == "S") {
    Small* s = new Small(this);
    ob = s;
  } else if (name == "N") {
    Normal* n = new Normal(this);
    ob = n;
  } else if (name == "D") {
    DragonHoard* d = new DragonHoard(this);
    ob = d;
  }
  floor->notifyTextDisplay(this);
}

// spawnPotion(name) spawns potion of type
//                  implied by name
void Tile::spawnPotion(string name) {
  if (name == "RH") {
    RestoreHP* rh = new RestoreHP(this);
    ob = rh;
  } else if (name == "BA") {
    BoostAtk* ba = new BoostAtk(this);
    ob = ba;
  } else if (name == "BD") {
    BoostDef* bd = new BoostDef(this);
    ob = bd;
  } else if (name == "PH") {
    PoisonHP* ph = new PoisonHP(this);
    ob = ph;
  } else if (name == "WA") {
    WoundAtk* wa = new WoundAtk(this);
    ob = wa;
  } else if (name == "WD") {
    WoundDef* wd = new WoundDef(this);
    ob = wd;
  }
  floor->notifyTextDisplay(this);
}

// spawnDragon(DH) spawns a dragon for the
//                 corresponing DH
void Tile::spawnDragon(Tile* DH) {
  Dragon* d = new Dragon(this, DH);
  ob = d;
  floor->notifyTextDisplay(this);
}
