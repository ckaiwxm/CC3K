#include <iostream>
#include <string>
#include "Drow.h"
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
Drow::Drow(): Player(150, 25, 15, "Drow") {}

Drow::~Drow() {}


// Override

// attackWho(h) lets this attack h
void Drow::attackWho(Halfling* h) {
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
void Drow::attackWho(Merchant* m) {
  Merchant::isMerchantAngry = true;
  attackCore(m);
}

// attackWho(h) lets this attack h
void Drow::attackWho(Human* h) {
  attackCore(h);
}

// attackWho(o) lets this attack o
void Drow::attackWho(Orcs* o) {
  attackCore(o);
}

// attackWho(d) lets this attack d
void Drow::attackWho(Dragon* d) {
  attackCore(d);
}

// attackWho(e) lets this attack e
void Drow::attackWho(Elf* e) {
  attackCore(e);
}

// attackWho(w) lets this attack w
void Drow::attackWho(Dwarf* w) {
  attackCore(w);
}

