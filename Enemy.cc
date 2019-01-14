#include <cstdlib>
#include <cmath>
#include <memory>
#include "Enemy.h"
#include "DragonHoard.h"
#include "Merchant.h"
#include "Dragon.h"
#include "Player.h"
#include "Floor.h"
#include "Tile.h"

// Player
#include "Shade.h"
#include "Drow.h"
#include "Troll.h"
#include "Vampire.h"
#include "Goblin.h"

using namespace std;

// Big 5
Enemy::Enemy(double hp, double atk, double def, std::string name, Tile* tile):
Character(hp, atk, def, name, tile) {}

Enemy::~Enemy() {}


// Attack

// moreDamage(defender, multi) calculates the damage made by defender
double Enemy::moreDamage(Player* defender, double multi) {
  float damage = (float)(100 / (100 + defender->getDef()));
  return ceil(damage * this->getAtk()) * multi;
}

// attackWhoCore(p, multi) let this attack p
void Enemy::attackWhoCore(Player* p, double multi) {
  int num = rand() % 2;
  if (num == 0) { // Miss
    string miss = name + " misses. ";
    tile->getFloor()->getTextDisplay()->addAction(miss);
  } else { // Attack
    int decreaseHp = moreDamage(p, multi);
    
    if ((p->getHp() - decreaseHp) > 0) { // Player dead or not
      p->setHp(p->getHp() - decreaseHp);
    } else {
      p->setHp(0);
    }
    
    string damage = name + " deals " + to_string(static_cast<int>(decreaseHp)) + " damage to PC. ";
    tile->getFloor()->getTextDisplay()->addAction(damage);
  }
}


// Move

// isNearPc(p) determines if p is within
//             one block radius
bool Enemy::isNearPc(Player *p) {
  int PcCol = p->getTile()->getCol();
  int PcRow = p->getTile()->getRow();
  int NpcCol = getTile()->getCol();
  int NpcRow = getTile()->getRow();
  if ((abs(PcCol - NpcCol) > 1) ||
      (abs(PcRow - NpcRow) > 1)) {
    return false;
  } else {
    return true;
  }
}

// enemyMove(p, ifFreeze) moves this Enemy
void Enemy::enemyMove(Player *p, bool ifFreeze) {
  if (isNearPc(p) == true || name == "Dragon") {
    //set
    p->attackBy(this);
    return;
  }
  if (ifFreeze == false && name != "Dragon") {
    vector<Tile*> emptyTiles;
    int row = this->tile->getRow();
    int col = this->tile->getCol();
    for (int i = -1; i < 2; ++i) {
      for (int j = -1; j < 2; ++j) {
        Tile* t = this->tile->getFloor()->findTile(i + row,j + col);
        if (t->getDisplay() == '.') {
          if (t->getObject() == nullptr) {
            emptyTiles.emplace_back(t);
          }
        }
      }
    }
    if (emptyTiles.size() > 0) {
      Tile* whichTile = emptyTiles[(rand() % emptyTiles.size())];
      this->tile->objectEmpty();
      
      whichTile->setObject(this);
      this->tile = whichTile;
    }
  }
}
