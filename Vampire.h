#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_
#include <iostream>
#include <string>
#include "Player.h"

class Vampire:public Player {
public:
  // Big 5
  Vampire();
  ~Vampire();
  
  // Override
  virtual void attackWho(Human* h) override;
  virtual void attackWho(Orcs* o) override;
  virtual void attackWho (Dragon* d) override;
  virtual void attackWho(Elf* e) override;
  virtual void attackWho(Dwarf* w) override;
  virtual void attackWho(Halfling* h) override;
  virtual void attackWho(Merchant* m) override;
  
};

#endif
