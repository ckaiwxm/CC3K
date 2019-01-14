#include <iostream>
#include <string>
#include <cstdlib>
#include "Vampire.h"
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
Vampire::Vampire(): Player(50, 25, 25, "Vampire") {}

Vampire::~Vampire() {}

// Override
// attackWho(h) lets this attack h
void Vampire::attackWho(Halfling* h) {
  int num = rand() % 2;
  if (num == 0) { // Miss
    string miss = "PC misses. ";
    tile->getFloor()->getTextDisplay()->addAction(miss);
    attackBy(h);
  } else { // Attack
    hp = hp + 5; // Ability
    attackCore(h);
  }
}

// attackWho(m) lets this attack m
void Vampire::attackWho(Merchant* m) {
  Merchant::isMerchantAngry = true;
  hp = hp + 5; // Ability
  attackCore(m);
}
// attackWho(h) lets this attack h
void Vampire::attackWho(Human* h) {
  hp = hp + 5; // Ability
  attackCore(h);
}

// attackWho(o) lets this attack o
void Vampire::attackWho(Orcs* o) {
  hp = hp + 5; // Ability
  attackCore(o);
}

// attackWho(d) lets this attack d
void Vampire::attackWho(Dragon* d) {
  hp = hp + 5; // Ability
  attackCore(d);
}

// attackWho(e) lets this attack e
void Vampire::attackWho(Elf* e) {
  hp = hp + 5; // Ability
  attackCore(e);
}

// attackWho(w) lets this attack w
void Vampire::attackWho(Dwarf* w) {
  attackCore(w);
}
