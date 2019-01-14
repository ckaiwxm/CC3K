#include <iostream>
#include <string>
#include <cstdlib>
#include "Shade.h"
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
Shade::Shade(): Player(125, 25, 25, "Shade") {}

Shade::~Shade() {}

// Override
// attackWho(h) lets this attack h
void Shade::attackWho(Halfling* h) {
  int num = rand() % 2;
  if (num == 0) { // Miss
    string miss = "PC misses. ";
    tile->getFloor()->getTextDisplay()->addAction(miss);
    attackBy(h);
  } else { // Attack
    attackCore(h);
  }
}

// attackWho(m) lets this attack m
void Shade::attackWho(Merchant* m) {
  Merchant::isMerchantAngry = true;
  attackCore(m);
}

// attackWho(h) lets this attack h
void Shade::attackWho(Human* h) {
  attackCore(h);
}

// attackWho(o) lets this attack o
void Shade::attackWho(Orcs* o) {
  attackCore(o);
}

// attackWho(d) lets this attack d
void Shade::attackWho(Dragon* d) {
  attackCore(d);
}

// attackWho(e) lets this attack e
void Shade::attackWho(Elf* e) {
  attackCore(e);
}

// attackWho(w) lets this attack w
void Shade::attackWho(Dwarf* w) {
  attackCore(w);
}

