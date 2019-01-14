#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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

// Tile
#include "Tile.h"
#include "HWall.h"
#include "VWall.h"
#include "Door.h"
#include "Space.h"
#include "Passage.h"
#include "Blank.h"

using namespace std;

// Big 5
//Ctor
Floor::Floor() {}

//Dtor
Floor::~Floor(){
  for (int row = 0; row < 25; ++row){
    for(int col = 0; col < 79; ++col){
      if (floor[row][col].getObject() != nullptr) {
        delete floor[row][col].getObject();
      }
    }
  }
  Chamber1.clear();
  Chamber2.clear();
  Chamber3.clear();
  Chamber4.clear();
  Chamber5.clear();
  floor.clear();
  delete td;
}


// cleanFloor() destroy every object on the tiles
void Floor::cleanFloor() {
  for (int row = 0; row < 25; ++row){
    for(int col = 0; col < 79; ++col){
      if (floor[row][col].getObject() != nullptr) {
        if (floor[row][col].getObject()->getName() != "Shade" &&
            floor[row][col].getObject()->getName() != "Vampire" &&
            floor[row][col].getObject()->getName() != "Troll" &&
            floor[row][col].getObject()->getName() != "Drow" &&
            floor[row][col].getObject()->getName() != "Goblin") {
            delete floor[row][col].getObject();
        }
      }
    }
  }
  Chamber1.clear();
  Chamber2.clear();
  Chamber3.clear();
  Chamber4.clear();
  Chamber5.clear();
  floor.clear();
  delete td;
}


// getPlayer() returns a pointer of player
Player* Floor::getPlayer() {
  return player;
}

// getLevel() return this level
int Floor::getLevel(){
  return level;
}

// changeFreezeState() sets this FreezeState to true
void Floor::changeFreezeState() {
  FreezeState = true;
}

// init() initialize a new floor and spawns all objects
void Floor::init(Player* player) {
  if (level != 0) {
    cleanFloor();
  }
  
  level += 1;
  string s;
  ifstream map("floor.txt");
  for (int r = 0; r < 25; ++r) {
    getline(map, s);
    std::vector<Tile> theFloor;
    for (int c = 0; c < 79; ++c) {
      if (s[c] == '-'){
        theFloor.emplace_back(HWall(c,r,this));
      }
      if (s[c] == '|'){
        theFloor.emplace_back(VWall(c,r,this));
      }
      if (s[c] == '.') {
        theFloor.emplace_back(Space(c,r,this));
      }
      if (s[c] == '+') {
        theFloor.emplace_back(Door(c,r,this));
      }
      if (s[c] == '#') {
        theFloor.emplace_back(Passage(c,r,this));
      }
      if (s[c] == ' ') {
        theFloor.emplace_back(Blank(c,r,this));
      }
    }
    floor.emplace_back(theFloor);
  }
  
  td = new TextDisplay(player,this);
  this->player = player;
  
  assignCham();
  spawnPlayer();
  spawnStair();
  spawnPotion();
  spawnGold();
  spawnEnemy();
}

// assignCham() set Tiles with their chamber number
void Floor::assignCham() {
  // Chamber 1
  for (int i = 3; i < 7; ++i) {
    for (int j = 3; j < 29; ++j) {
      Chamber1.emplace_back(findTile(i,j));
    }
  }
  // Chamber 2
  for (int i = 3; i < 5; ++i) {
    for (int j = 39; j < 62; ++j) {
      Chamber2.emplace_back(findTile(i,j));
    }
  }
  for (int j = 39; j < 70; ++j) {
    Chamber2.emplace_back(findTile(5,j));
  }
  for (int j = 39; j < 73; ++j) {
    Chamber2.emplace_back(findTile(6,j));
  }
  for (int i = 7; i < 13 ; ++i) {
    for (int j = 61; j < 76; ++j) {
      Chamber2.emplace_back(findTile(i,j));
    }
  }
  //Chamber 3
  for (int i = 10; i < 13; ++i) {
    for (int j = 38; j < 50 ; ++j) {
      Chamber3.emplace_back(findTile(i,j));
    }
  }
  //Chamber 4
  for (int i = 15; i < 22; ++i) {
    for (int j = 4; j < 25 ; ++j) {
      Chamber4.emplace_back(findTile(i,j));
    }
  }
  //Chamber 5
  for (int i = 16; i < 19; ++i){
    for (int j = 65; j < 76; ++j) {
      Chamber5.emplace_back(findTile(i,j));
    }
  }
  for (int i = 19; i < 22; ++i) {
    for (int j = 37; j < 76; ++j) {
      Chamber5.emplace_back(findTile(i,j));
    }
  }
}

// findTile(int col,int row) find the pointer to
//                           the tile at (col,row)
Tile* Floor::findTile(int row,int col) {
  return &floor[row][col];
}


// Spawn
//spawnPlayer() randomly spawn
void Floor::spawnPlayer() {
  int whichChamber = rand() % 5;
  this->bornChamber = whichChamber;
  int whichTile = 0;
  if (whichChamber == 0) {
    whichTile = rand() % Chamber1.size();
    Chamber1.at(whichTile)->spawnPlayer(player);
  }
  if (whichChamber == 1) {
    whichTile = rand() % Chamber2.size();
    Chamber2.at(whichTile)->spawnPlayer(player);
  }
  if (whichChamber == 2) {
    whichTile = rand() % Chamber3.size();
    Chamber3.at(whichTile)->spawnPlayer(player);
  }
  if (whichChamber == 3) {
    whichTile = rand() % Chamber4.size();
    Chamber4.at(whichTile)->spawnPlayer(player);
  }
  if (whichChamber == 4) {
    whichTile = rand() % Chamber5.size();
    Chamber5.at(whichTile)->spawnPlayer(player);
  }
}


//spawnStair() randomly spawn Stair in a chamber which is
//             different from the chamber where player spawned
void Floor::spawnStair() {
  int whichChamber = rand() % 5;
  while (whichChamber == this->bornChamber) {
    whichChamber = rand() % 5;
  }
  int whichTile = 0;
  if (whichChamber == 0) {
    whichTile = rand() % Chamber1.size();
    Chamber1.at(whichTile)->Tile::spawnStair();
  }
  if (whichChamber == 1) {
    whichTile = rand() % Chamber2.size();
    Chamber2.at(whichTile)->Tile::spawnStair();
  }
  if (whichChamber == 2) {
    whichTile = rand() % Chamber3.size();
    Chamber3.at(whichTile)->Tile::spawnStair();
  }
  if (whichChamber == 3) {
    whichTile = rand() % Chamber4.size();
    Chamber4.at(whichTile)->Tile::spawnStair();
  }
  if (whichChamber == 4) {
    whichTile = rand() % Chamber5.size();
    Chamber5.at(whichTile)->Tile::spawnStair();
  }
}


//spawnEnemy() choose a chamber and an enemy type to
//             randomly spawn 20 enemies
void Floor::spawnEnemy() {
  for (int i = 0 ; i < (maxEnemy - dragonNum); ++i) {
    int whichChamber = rand() % 5;
    int whichEnemy = rand() % 18;
    int whichTile = 0;
    if (whichChamber == 0) {
      whichTile = rand() % Chamber1.size();
      while (Chamber1.at(whichTile)->getObject() != nullptr) {
        whichTile = rand() % Chamber1.size();
      }
      Chamber1.at(whichTile)->spawnEnemy(enemyName[whichEnemy]);
    }
    if (whichChamber == 1) {
      whichTile = rand() % Chamber2.size();
      while (Chamber2.at(whichTile)->getObject() != nullptr) {
        whichTile = rand() % Chamber2.size();
      }
      Chamber2.at(whichTile)->spawnEnemy(enemyName[whichEnemy]);
    }
    if (whichChamber == 2) {
      whichTile = rand() % Chamber3.size();
      while (Chamber3.at(whichTile)->getObject() != nullptr) {
        whichTile = rand() % Chamber3.size();
      }
      Chamber3.at(whichTile)->spawnEnemy(enemyName[whichEnemy]);
    }
    if (whichChamber == 3) {
      whichTile = rand() % Chamber4.size();
      while (Chamber4.at(whichTile)->getObject() != nullptr) {
        whichTile = rand() % Chamber4.size();
      }
      Chamber4.at(whichTile)->spawnEnemy(enemyName[whichEnemy]);
    }
    if (whichChamber == 4) {
      whichTile = rand() % Chamber5.size();
      while (Chamber5.at(whichTile)->getObject() != nullptr) {
        whichTile = rand() % Chamber5.size();
      }
      Chamber5.at(whichTile)->spawnEnemy(enemyName[whichEnemy]);
    }
  }
}

//spawnDragon() takes in t and spawns a dragon within
//              oneblock of its dragonhoard
void Floor::spawnDragon(Tile* t) {
  vector<Tile*> emptyTiles;
  int col = t->getCol();
  int row = t->getRow();
  for (int i = -1; i < 2; ++i) {
    for (int j = -1; j < 2; ++j) {
      Tile* tmp = findTile(i + row,j + col);
      if ((tmp->getObject() == nullptr)
          && tmp->getDisplay() == '.'){
        emptyTiles.emplace_back(tmp);
      }
    }
  }
  if (emptyTiles.size() <= 0) {
    return;
  }
  int which = rand() % emptyTiles.size();
  emptyTiles.at(which)->Tile::spawnDragon(t);
  dragonNum += 1;
}


//spawnGold() choose a chamber and a gold type to
//            randomly spawn 10 gold
void Floor::spawnGold() {
  for (int i = 0 ; i < maxGold; ++i) {
    int whichChamber = rand() % 5;
    int whichGold = rand() % 8;
    int whichTile = 0;
    if (whichChamber == 0) {
      whichTile = rand() % Chamber1.size();
      while (Chamber1.at(whichTile)->getObject() != nullptr) {
        whichTile = rand() % Chamber1.size();
      }
      Chamber1.at(whichTile)->spawnGold(goldName[whichGold]);
      if (goldName[whichGold] == "D") {
        spawnDragon( Chamber1.at(whichTile) );
      }
    }
    if (whichChamber == 1) {
      whichTile = rand() % Chamber2.size();
      while (Chamber2.at(whichTile)->getObject() != nullptr) {
        whichTile = rand() % Chamber2.size();
      }
      Chamber2.at(whichTile)->spawnGold(goldName[whichGold]);
      if (goldName[whichGold] == "D") {
        spawnDragon( Chamber2.at(whichTile) );
      }
    }
    if (whichChamber == 2) {
      whichTile = rand() % Chamber3.size();
      while (Chamber3.at(whichTile)->getObject() != nullptr) {
        whichTile = rand() % Chamber3.size();
      }
      Chamber3.at(whichTile)->spawnGold(goldName[whichGold]);
      if (goldName[whichGold] == "D") {
        spawnDragon( Chamber3.at(whichTile) );
      }
    }
    if (whichChamber == 3) {
      whichTile = rand() % Chamber4.size();
      while (Chamber4.at(whichTile)->getObject() != nullptr) {
        whichTile = rand() % Chamber4.size();
      }
      Chamber4.at(whichTile)->spawnGold(goldName[whichGold]);
      if (goldName[whichGold] == "D") {
        spawnDragon( Chamber4.at(whichTile) );
      }
    }
    if (whichChamber == 4) {
      whichTile = rand() % Chamber5.size();
      while (Chamber5.at(whichTile)->getObject() != nullptr) {
        whichTile = rand() % Chamber5.size();
      }
      Chamber5.at(whichTile)->spawnGold(goldName[whichGold]);
      if (goldName[whichGold] == "D") {
        spawnDragon( Chamber5.at(whichTile) );
      }
    }
  }
}


// spawnPotion() choose a chamber and a potion type to
//               randomly spawn 10 potion
void Floor::spawnPotion() {
  for (int i = 0 ; i < maxPotion; ++i) {
    int whichChamber = rand() % 5;
    int whichPotion = rand() % 6;
    int whichTile = 0;
    if (whichChamber == 0) {
      whichTile = rand() % Chamber1.size();
      while (Chamber1.at(whichTile)->getObject() != nullptr) {
        whichTile = rand() % Chamber1.size();
      }
      Chamber1.at(whichTile)->spawnPotion(potionName[whichPotion]);
    }
    if (whichChamber == 1) {
      whichTile = rand() % Chamber2.size();
      while (Chamber2.at(whichTile)->getObject() != nullptr) {
        whichTile = rand() % Chamber2.size();
      }
      Chamber2.at(whichTile)->spawnPotion(potionName[whichPotion]);
    }
    if (whichChamber == 2) {
      whichTile = rand() % Chamber3.size();
      while (Chamber3.at(whichTile)->getObject() != nullptr) {
        whichTile = rand() % Chamber3.size();
      }
      Chamber3.at(whichTile)->spawnPotion(potionName[whichPotion]);
    }
    if (whichChamber == 3) {
      whichTile = rand() % Chamber4.size();
      while (Chamber4.at(whichTile)->getObject() != nullptr) {
        whichTile = rand() % Chamber4.size();
      }
      Chamber4.at(whichTile)->spawnPotion(potionName[whichPotion]);
    }
    if (whichChamber == 4) {
      whichTile = rand() % Chamber5.size();
      while (Chamber5.at(whichTile)->getObject() != nullptr) {
        whichTile = rand() % Chamber5.size();
      }
      Chamber5.at(whichTile)->spawnPotion(potionName[whichPotion]);
    }
  }
}


// moveEnemy() will move all alive enemies after player
//             made a movement
void Floor::moveEnemy(Enemy* enemy) {
  for (int row = 0; row < 25; ++row){
    for(int col = 0; col < 79; ++col){
      if (floor[row][col].getObject() != nullptr) {
        string isEnemy = floor[row][col].getObject()->getName();
        if (isEnemy == "Human"
            || isEnemy == "Dwarf"
            || isEnemy == "Elf"
            || isEnemy == "Orcs"
            || isEnemy == "Merchant"
            || isEnemy == "Halfling"
            || isEnemy == "Dragon") {
          if (floor[row][col].getObject() != enemy) {
            if (floor[row][col].getObject()->getHasMoved() == false) {
              floor[row][col].getObject()->setHasMoved(true);
              dynamic_cast<Enemy*>(floor[row][col].getObject())->enemyMove(player, FreezeState);
            }
          }
        }
      }
    }
  }
  for (int row = 0; row < 25; ++row){
    for(int col = 0; col < 79; ++col){
      if (floor[row][col].getObject() != nullptr) {
        floor[row][col].getObject()->setHasMoved(false);
      }
    }
  }
}


// Interact
// dirTile(myR, myC, dir) returns reference to the tile
//                        in the direction dir
Tile* Floor::dirTile(int myR, int myC, string dir) {
  if (dir == "nw") {
    return &floor[myR - 1][myC - 1];
  } else if (dir == "no") {
    return &floor[myR - 1][myC];
  } else if (dir == "ne") {
    return &floor[myR - 1][myC + 1];
  } else if (dir == "we") {
    return &floor[myR][myC - 1];
  } else if (dir == "ea") {
    return &floor[myR][myC + 1];
  } else if (dir == "sw") {
    return &floor[myR + 1][myC - 1];
  } else if (dir == "so") {
    return &floor[myR + 1][myC];
  } else { // se
    return &floor[myR + 1][myC + 1];
  }
}

// pPotion(dir) takes a dir and returns true if the player
//              pick up the potion successfully, false otherwise
bool Floor::pPotion(string dir){
  int myR = this->player->getTile()->getRow();
  int myC = this->player->getTile()->getCol();
  Tile* potionPos = dirTile(myR, myC, dir);
  
  if (potionPos->getObject() == nullptr) { // Nothing
    return false;
  } else {
    // Has something, it is potion
    if (potionPos->getObject()->getName() == "RH") {
      player->pickPotion(dynamic_cast<RestoreHP*>(potionPos->getObject()));
      moveEnemy(nullptr);
      return true;
    } else if (potionPos->getObject()->getName() == "BA") {
      player->pickPotion(dynamic_cast<BoostAtk*>(potionPos->getObject()));
      moveEnemy(nullptr);
      return true;
    } else if (potionPos->getObject()->getName() == "BD") {
      player->pickPotion(dynamic_cast<BoostDef*>(potionPos->getObject()));
      moveEnemy(nullptr);
      return true;
    } else if (potionPos->getObject()->getName() == "PH") {
      player->pickPotion(dynamic_cast<PoisonHP*>(potionPos->getObject()));
      moveEnemy(nullptr);
      return true;
    } else if (potionPos->getObject()->getName() == "WA") {
      player->pickPotion(dynamic_cast<WoundAtk*>(potionPos->getObject()));
      moveEnemy(nullptr);
      return true;
    } else if (potionPos->getObject()->getName() == "WD") {
      player->pickPotion(dynamic_cast<WoundDef*>(potionPos->getObject()));
      moveEnemy(nullptr);
      return true;
    } else { // Has something not potion
      return false;
    }
  }
}


// pAttack(dir) takes a dir and returns true if player successfully
//              attack enemy and false otherwise
bool Floor::pAttack(string dir) {
  int myR = this->player->getTile()->getRow();
  int myC = this->player->getTile()->getCol();
  Tile* enemyPos = dirTile(myR, myC, dir);
  
  if (enemyPos->getObject() == nullptr) { // Nothing
    return false;
  } else {
    // Has something, it is enemy
    if (enemyPos->getObject()->getName() == "Human") {
      player->attackWho(dynamic_cast<Human*>(enemyPos->getObject()));
      moveEnemy(dynamic_cast<Enemy*>(enemyPos->getObject()));
      return true;
    } else if (enemyPos->getObject()->getName() == "Dwarf") {
      player->attackWho(dynamic_cast<Dwarf*>(enemyPos->getObject()));
      moveEnemy(dynamic_cast<Enemy*>(enemyPos->getObject()));
      return true;
    } else if (enemyPos->getObject()->getName() == "Elf") {
      player->attackWho(dynamic_cast<Elf*>(enemyPos->getObject()));
      moveEnemy(dynamic_cast<Enemy*>(enemyPos->getObject()));
      return true;
    } else if (enemyPos->getObject()->getName() == "Orcs") {
      player->attackWho(dynamic_cast<Orcs*>(enemyPos->getObject()));
      moveEnemy(dynamic_cast<Enemy*>(enemyPos->getObject()));
      return true;
    } else if (enemyPos->getObject()->getName() == "Merchant") {
      player->attackWho(dynamic_cast<Merchant*>(enemyPos->getObject()));
      moveEnemy(dynamic_cast<Enemy*>(enemyPos->getObject()));
      return true;
    } else if (enemyPos->getObject()->getName() == "Dragon") {
      player->attackWho(dynamic_cast<Dragon*>(enemyPos->getObject()));
      moveEnemy(dynamic_cast<Enemy*>(enemyPos->getObject()));
      return true;
    } else if (enemyPos->getObject()->getName() == "Halfling") {
      player->attackWho(dynamic_cast<Halfling*>(enemyPos->getObject()));
      moveEnemy(dynamic_cast<Enemy*>(enemyPos->getObject()));
      return true;
    } else {
      return false;
    }
  }
}

// pMoveTo(dir) takses a dir, returns true if the player is
//              moved successfully and false otherwise
bool Floor::pMoveTo(string dir) {
  int myR = this->player->getTile()->getRow();
  int myC = this->player->getTile()->getCol();
  Tile* intend = dirTile(myR, myC, dir);
  
  if (intend->getDisplay() == '.' ||
      intend->getDisplay() == '+' ||
      intend->getDisplay() == '#') {
    if (intend->getObject() != nullptr) {  // has object
      if (intend->getObject()->getName() == "G" ||
          (intend->getObject()->getName() == "DH" &&   //Gold & DragonHoard
           dynamic_cast<DragonHoard*>(intend->getObject())->getDragonDead())) { //Gold & DragonHoard
            player->useGold(dynamic_cast<Gold*>(intend->getObject()));
            player->playerMove(intend, dir);
            moveEnemy(nullptr);
            return true;
          } else if (intend->getObject()->getName() == "Stair") { //Stair
            init(player);
            return true;
          } else {
            return false;
          }
    } else { // Empty, can move to
      player->playerMove(intend, dir);
      moveEnemy(nullptr);
      return true;
    }
  } else {
    return false;
  }
}

// TextDisplay
// getTextDisplay() returns a pointer to textdisplay
TextDisplay* Floor::getTextDisplay() {
  return td;
}

// notifyTextDisplay(fromWho) notifies textdisplay of fromWho
void Floor::notifyTextDisplay(Tile* fromWho) {
  td->notify(fromWho);
}

// clearTextDisplay() does not display message on the screen
void Floor::clearTextDisplay() {
  td->cleanAction();
}

// prints
// operator<<(out, floor) prints floor's textdisplay on the screen
std::ostream &operator<<(std::ostream &out, const Floor &floor) {
  out << *(floor.td);
  return out;
}
