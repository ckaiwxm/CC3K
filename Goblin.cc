#include <iostream>
#include <string>
#include "Goblin.h"
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
Goblin::Goblin(): Player(110, 15, 20, "Goblin") {}

Goblin::~Goblin() {}


// Override

// attackWho(h) lets this attack h
void Goblin::attackWho(Halfling* h) {
  int num = rand() % 2;
  if (num == 0) { // Miss
    string miss = "PC misses. ";
    tile->getFloor()->getTextDisplay()->addAction(miss);
    attackBy(h);
  } else { // Attack
    attackCore(h);
    if (h->isAlive() == false) {
      gold =  gold + 5; // Ability
    }
  }
}

// attackWho(m) lets this attack m
void Goblin::attackWho(Merchant* m) {
  Merchant::isMerchantAngry = true;
  attackCore(m);
  if (m->isAlive() == false) {
    gold =  gold + 5; // Ability
  }
}

// attackWho(h) lets this attack h
void Goblin::attackWho(Human* h) {
  attackCore(h);
  if (h->isAlive() == false) {
    gold =  gold + 5; // Ability
  }
}

// attackWho(o) lets this attack o
void Goblin::attackWho(Orcs* o) {
  attackCore(o);
  if (o->isAlive() == false) {
    gold =  gold + 5; // Ability
  }
}

// attackWho(d) lets this attack d
void Goblin::attackWho(Dragon* d) {
  attackCore(d);
  if (d->isAlive() == false) {
    gold =  gold + 5; // Ability
  }
}

// attackWho(e) lets this attack e
void Goblin::attackWho(Elf* e) {
  attackCore(e);
  if (e->isAlive() == false) {
    gold =  gold + 5; // Ability
  }
}

// attackWho(w) lets this attack w
void Goblin::attackWho(Dwarf* w) {
  attackCore(w);
  if (w->isAlive() == false) {
    gold =  gold + 5; // Ability
  }
}


