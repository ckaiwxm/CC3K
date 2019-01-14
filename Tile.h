#ifndef _TILE_H_
#define _TILE_H_
#include <iostream>
class Floor;
class TextDisplay;
class Object;
class Gold;
class Potion;
class Player;
class Enemy;

class Tile {
protected:
  char display;
  int col, row;
  Floor* floor = nullptr;
  Object* ob = nullptr;
  
public:
  // Big 5
  Tile(int col, int row, Floor* floor);
  virtual ~Tile();
  
  // Get fields
  char getDisplay() const;
  int getCol() const;
  int getRow() const;
  Floor* getFloor() const;
  Object* getObject() const;
  
  // Set fields
  void setObject(Object* newOb);
  void objectEmpty();
  void objectDestroy();
  
  // Spawn
  void spawnPlayer(Player* p);
  void spawnStair();
  void spawnEnemy(char name);
  void spawnGold(std::string name);
  void spawnPotion(std::string name);
  void spawnDragon(Tile* DH);
};

#endif
