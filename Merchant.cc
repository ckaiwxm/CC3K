#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "Merchant.h"
#include "Player.h"
#include "Floor.h"

using namespace std;

Merchant::Merchant(Tile* tile):
Enemy(30, 70, 5, "Merchant", tile) {}

Merchant::~Merchant() {}


bool Merchant::isMerchantAngry = false;

// attackWho(g, multi) lets this attack g
void Merchant::attackWho(Goblin* g, double multi) {
  (void) multi;
  if (Merchant::isMerchantAngry) {
    attackWhoCore(g);
  }
}

// attackWho(t, multi) lets this attack t
void Merchant::attackWho(Troll* t, double multi){
  (void) multi;
  if (Merchant::isMerchantAngry) {
    attackWhoCore(t);
  }
}

// attackWho(s, multi) lets this attack s
void Merchant::attackWho(Shade* s, double multi) {
  (void) multi;
  if (Merchant::isMerchantAngry) {
    attackWhoCore(s);
  }
}

// attackWho(v, multi) lets this attack v
void Merchant::attackWho(Vampire* v,double multi) {
  (void) multi;
  if (Merchant::isMerchantAngry) {
    attackWhoCore(v);
  }
}

// attackWho(d, multi) lets this attack d
void Merchant::attackWho(Drow* d,double multi) {
  (void) multi;
  if (Merchant::isMerchantAngry) {
    attackWhoCore(d);
  }
}

// attackBy(player) lets this attacked by player
void Merchant::attackBy(Player* player){
  if (player->getName() == "Shade") {
    attackWho(dynamic_cast<Shade*>(player));
  }
  else if (player->getName() == "Vampire") {
    attackWho(dynamic_cast<Vampire*>(player));
  }
  else if (player->getName() == "Troll") {
    attackWho(dynamic_cast<Troll*>(player));
  }
  else if (player->getName() == "Drow") {
    attackWho(dynamic_cast<Drow*>(player));
  }
  else if (player->getName() == "Goblin") {
    attackWho(dynamic_cast<Goblin*>(player));
  }
}

