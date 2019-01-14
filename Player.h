#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
class Tile;
class Floor;
class TextDisplay;
class Potion;
class Gold;
class Enemy;

//Enemies
class Merchant;
class Halfling;
class Dwarf;
class Orcs;
class Elf;
class Human;
class Dragon;


class Player:public Character {
protected:
  double oldAtk;
  double oldDef;
  double gold = 0;
  std::vector<std::string> knownPotion;
  void attackCore(Enemy* enemy);
  
private:
  std::string getAct(std::string dir);
  double getDamage(Enemy* e);
  
public:
  // Big 5
  Player(double hp, double atk, double def, std::string name);
  virtual ~Player() = 0;
  
  // Get field
  double getOldAtk() const;
  double getOldDef() const;
  double getGold() const;
  
  // Set field
  void setGold(double newGold);
  
  // Attack
  virtual void attackWho(Human* h) = 0;
  virtual void attackWho(Orcs* o) = 0;
  virtual void attackWho (Dragon* d) = 0;
  virtual void attackWho(Elf* e) = 0;
  virtual void attackWho(Dwarf* w) = 0;
  virtual void attackWho(Halfling* h) = 0;
  virtual void attackWho(Merchant* m) = 0;

  void attackBy(Enemy* p);
  
  // Potion
  void pickPotion(Potion* p);
  
  // Gold
  void useGold(Gold* g);
  
  // Move
  void playerMove(Tile* intend, std::string dir);
};

#endif
