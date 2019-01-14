#include <iostream>
#include <string>
#include "Troll.h"
#include "Floor.h"

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
Troll::Troll(): Player(120, 25, 15, "Troll") {}

Troll::~Troll() {}

// attackWho(h) lets this attack h
void Troll::attackWho(Halfling* h) {
  int num = rand() % 2;
  if (num == 0) { // Miss
    string miss = "PC misses. ";
    tile->getFloor()->getTextDisplay()->addAction(miss);
    attackBy(h);
  } else { // Attack
    if ((hp + 5) >= 120) { // Ability
      hp = 120;
    } else {
      hp = hp + 5;
    }
    attackCore(h);
  }
}

// attackWho(m) lets this attack m
void Troll::attackWho(Merchant* m) {
  Merchant::isMerchantAngry = true;
  if ((hp + 5) >= 120) { // Ability
    hp = 120;
  } else {
    hp = hp + 5;
  }
  attackCore(m);
}

// attackWho(h) lets this attack h
void Troll::attackWho(Human* h) {
  if ((hp + 5) >= 120) { // Ability
    hp = 120;
  } else {
    hp = hp + 5;
  }
  attackCore(h);
}

// attackWho(o) lets this attack o
void Troll::attackWho(Orcs* o) {
  if ((hp + 5) >= 120) { // Ability
    hp = 120;
  } else {
    hp = hp + 5;
  }
  attackCore(o);
}

// attackWho(d) lets this attack d
void Troll::attackWho(Dragon* d) {
  if ((hp + 5) >= 120) { // Ability
    hp = 120;
  } else {
    hp = hp + 5;
  }
  attackCore(d);
}

// attackWho(e) lets this attack e
void Troll::attackWho(Elf* e) {
  if ((hp + 5) >= 120) { // Ability
    hp = 120;
  } else {
    hp = hp + 5;
  }
  attackCore(e);
}

// attackWho(w) lets this attack w
void Troll::attackWho(Dwarf* w) {
  if ((hp + 5) >= 120) { // Ability
    hp = 120;
  } else {
    hp = hp + 5;
  }
  attackCore(w);
}


