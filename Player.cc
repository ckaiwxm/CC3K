#include <iostream>
#include <string>
#include <cmath>
#include <memory>
#include <cstdlib>
#include "Player.h"
#include "Tile.h"
#include "Floor.h"
#include "TextDisplay.h"
#include "Potion.h"
#include "Gold.h"
#include "Dragon.h"
#include "DragonHoard.h"
#include "Enemy.h"

//Enemys
#include "Merchant.h"
#include "Halfling.h"
#include "Dwarf.h"
#include "Orcs.h"
#include "Elf.h"
#include "Human.h"
#include "Dragon.h"

using namespace std;

// Big 5
Player::Player(double hp, double atk, double def, std::string name):
Character(hp, atk, def, name, nullptr) {
  oldAtk = atk;
  oldDef = def;
}

Player::~Player() {}

// Get field
// getOldAtk() returns this oldAtk
double Player::getOldAtk() const {
  return oldAtk;
}

// getOldDef() returns this oldDef
double Player::getOldDef() const {
  return oldDef;
}

// getGold() returns this gold
double Player::getGold() const {
  return gold;
}


// Set field
// setGold(newGold) sets this gold to newGold
void Player::setGold(double newGold) {
  gold = newGold;
}
  

// Potion
// pickPotion(p) lets p to use potion
void Player::pickPotion(Potion* p) {
  // debug
  if (p == nullptr) {
    throw "ERR: nullptr Potion!";
  }
  //
  string potionName = p->getName();
  bool known = false;
  
  if (name == "Shade") {
    p->usePotion(dynamic_cast<Shade*>(this));
  }
  else if (name == "Vampire") {
    p->usePotion(dynamic_cast<Vampire*>(this));
  }
  else if (name == "Troll") {
    p->usePotion(dynamic_cast<Troll*>(this));
  }
  else if (name == "Drow") {
    p->usePotion(dynamic_cast<Drow*>(this));
  }
  else if (name == "Goblin") {
    p->usePotion(dynamic_cast<Goblin*>(this));
  }
  
  for (int i = 0; i < static_cast<int>(knownPotion.size()); ++i) {
    if (knownPotion.at(i) == potionName) {
      known = true;
    }
  }
  if (known == true) {
    string act = "PC uses " + potionName + ". ";
    tile->getFloor()->getTextDisplay()->addAction(act);
  } else {
    knownPotion.emplace_back(potionName);
    string act = "PC uses unknown potion (" + potionName + "). ";
    tile->getFloor()->getTextDisplay()->addAction(act);
  }
}

// Attack


  // Helper
// getDamage(e) calculates damage done by e
double Player::getDamage(Enemy* e) {
  float damage = (float)(100 / (100 + e->getDef()));
  return ceil(damage * this->getAtk());
}

//Protect helper method
// attackCore(enemy) lets this attack enemy
void Player::attackCore(Enemy* enemy) {
  if (enemy == nullptr) { // Attack air
    throw "Fail to attack enemy. ";
  }
  
  int decreaseHp = getDamage(enemy);
  string defender = enemy->getName();
  if ((enemy->getHp() - decreaseHp) > 0) {
    enemy->setHp(enemy->getHp() - decreaseHp);
    attackBy(enemy);
  } else {
    enemy->setHp(0);
    if (defender == "Dragon") {
      dynamic_cast<Dragon*>(enemy)
        ->getDragonHoard()->setDragonDead();
    }
    enemy->getTile()->objectDestroy();
  }
  
  string damage = "PC deals " +
    to_string(static_cast<int>(decreaseHp)) + " damage to "
    + defender + " ("
    + to_string(static_cast<int>(enemy->getHp())) + "). ";
  tile->getFloor()->getTextDisplay()->addAction(damage);
}

// attackBy(e) lets this attacked by e
void Player::attackBy(Enemy* e) {
  if (e->getName() == "Merchant") {
    (dynamic_cast<Merchant*>(e))->attackBy(this);
  }
  else if (e->getName() == "Halfling") {
    (dynamic_cast<Halfling*>(e))->attackBy(this);
  }
  else if (e->getName() == "Dwarf") {
    (dynamic_cast<Dwarf*>(e))->attackBy(this);
  }
  else if (e->getName() == "Orcs") {
    (dynamic_cast<Orcs*>(e))->attackBy(this);
  }
  else if (e->getName() == "Human") {
    (dynamic_cast<Human*>(e))->attackBy(this);
  }
  else if (e->getName() == "Dragon") {
    (dynamic_cast<Dragon*>(e))->attackBy(this);
  }
  else if (e->getName() == "Elf") {
    (dynamic_cast<Elf*>(e))->attackBy(this);
  }
}

// Gold
// useGold(g) lets this use g
void Player::useGold(Gold* g) {
  double goldNum = g->getValue();
  g->pickGold(this);
  
  string act = "PC picks up "
    + to_string(static_cast<int>(goldNum))
    + " gold. ";
  tile->getFloor()->getTextDisplay()->addAction(act);
}


// Move
// getAct(dir) takes in dir and returns the
//             direction of movement
string Player::getAct(string dir) {
  string detailDir = "";
  if (dir == "nw") {
    detailDir = "Northwest";
  } else if (dir == "no") {
    detailDir = "North";
  } else if (dir == "ne") {
    detailDir = "Northeast";
  } else if (dir == "we") {
    detailDir = "West";
  } else if (dir == "ea") {
    detailDir = "East";
  } else if (dir == "sw") {
    detailDir = "Southwest";
  } else if (dir == "so") {
    detailDir = "South";
  } else { // se
    detailDir = "Southeast";
  }
  string act = "PC moves to " + detailDir + ". ";
  return act;
}

// playerMove(intend, dir) moves this player to desired direction
void Player::playerMove(Tile* intend, string dir) {
  tile->objectEmpty();
      
  intend->setObject(this);
  tile = intend;
      
  string act = getAct(dir);
  tile->getFloor()->getTextDisplay()->addAction(act);
  
  // Player is Troll, ability invoked
  if (name == "Troll") {
    if ((hp + 5) >= 120) {
      hp = 120;
    } else {
      hp = hp + 5;
    }
  }
}
