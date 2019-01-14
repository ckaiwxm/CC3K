#ifndef _CHAR_H_
#define _CHAR_H_

#include <iostream>
#include "Object.h"
class Tile;
class Floor;
class TextDisplay;
class Goblin;
class Halfling;
class Dwarf;
class Troll;
class Merchant;

class Character:public Object {
protected:
  double hp, atk, def;
  
public:
  // Big 5
  Character(double hp, double atk, double def, std::string name, Tile* tile);
  virtual ~Character() = 0;
  
  // Get fields
  double getHp() const;
  double getAtk() const;
  double getDef() const;
  
  bool isAlive() const;
  
  // Set fields
  void setHp(double newHp);
  void setAtk(double newAtk);
  void setDef(double newDef);
  
};

#endif
