#ifndef _Floor_H_
#define _Floor_H_

#include <iostream>
#include <vector>
#include "TextDisplay.h"
#include "Tile.h"
#include "Player.h"
#include "Enemy.h"
#include "Stair.h"
#include "Gold.h"
#include "Potion.h"

class Tile;
class Player;
class Enemy;
class Stair;
class Gold;
class Potion;
class TextDisplay;

class Floor {
protected:
  Player* player;
  std::vector<std::vector<Tile>> floor;
  char enemyName[18] = {'H','H','H','H','W','W','W','E','E','O','O','M','M','L','L','L','L','L'};
  std::string potionName[6] = {"RH","BA","BD","PH","WA","WD"};
  std::string goldName[8] = {"S","S","N","N","N","N","N","D"};
  int level = 0;
  int dragonNum = 0;
  int maxEnemy = 20;
  int maxGold = 10;
  int maxPotion = 10;
  int bornChamber = 0;
  bool FreezeState = false;
  std::vector<Tile*> Chamber1;
  std::vector<Tile*> Chamber2;
  std::vector<Tile*> Chamber3;
  std::vector<Tile*> Chamber4;
  std::vector<Tile*> Chamber5;
  TextDisplay* td = nullptr;

private:
  Tile* dirTile(int myR, int myC, std::string dir);

public:
  // Big 5
  Floor();
  ~Floor();

  void cleanFloor();
  Player* getPlayer();
  int getLevel();
  void changeFreezeState();
  void init(Player* player);
  void assignCham();
  Tile* findTile(int row,int col);
  
  // Spawn
  void spawnPlayer();
  void spawnStair();
  void spawnEnemy();
  void spawnDragon(Tile* t);
  void spawnGold();
  void spawnPotion();
  void moveEnemy(Enemy* enemy);
  
  // Interact
  bool pPotion(std::string dir);
  bool pAttack(std::string dir);
  bool pMoveTo(std::string dir);
  
  // TextDisplay
  TextDisplay* getTextDisplay();
  void notifyTextDisplay(Tile* fromWho);
  void clearTextDisplay();
  
friend std::ostream &operator<<(std::ostream &out, const Floor& f);
};

#endif 

