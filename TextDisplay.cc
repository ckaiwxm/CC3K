#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "TextDisplay.h"
#include "Tile.h"
#include "Floor.h"
#include "Player.h"
#include "Object.h"

using namespace std;

// TextDisplay(n) constructs a new TextDisplay
// Effect: allocate heap memory
TextDisplay::TextDisplay(Player* player, Floor* floor):
player{player}, floor{floor} {
  string s;
  // For debug
  ifstream map("floor.txt");
  for (int r = 0; r < rowSize; ++r) {
    getline(map, s);
    vector<char> vc;
    for (int c = 0; c < colSize; ++c) {
      vc.emplace_back(s[c]);
    }
    theDisplay.emplace_back(vc);
  }
}

// ~TextDisplay() destructs this TextDisplay
// Effect: deallocate heap memory
TextDisplay::~TextDisplay() {
  for (int r = 0; r < rowSize; ++r) {
    theDisplay[r].clear();
  }
  theDisplay.clear();
}

// notify(who) updates the text displayed on the
//             screen according to the given Tile who
void TextDisplay::notify(Tile* who) {
  int r = who->getRow();
  int c = who->getCol();
  
  if (who->getObject() == nullptr) { // Empty Tile
    theDisplay[r][c] = who->getDisplay();
  } else { // Not empty
    string name = who->getObject()->getName();
    if (name == "Shade"
        || name == "Drow"
        || name == "Vampire"
        || name == "Troll"
        || name == "Goblin") { // Player
      theDisplay[r][c] = '@';
    } else if (name == "Human") { // Enemy
      theDisplay[r][c] = 'H';
    } else if (name == "Dwarf") {
      theDisplay[r][c] = 'W';
    } else if (name == "Elf") {
      theDisplay[r][c] = 'E';
    } else if (name == "Orcs") {
      theDisplay[r][c] = 'O';
    } else if (name == "Merchant") {
      theDisplay[r][c] = 'M';
    } else if (name == "Dragon") {
      theDisplay[r][c] = 'D';
    } else if (name == "Halfling") {
      theDisplay[r][c] = 'L';
    } else if (name == "RH"
               || name == "BA"
               || name == "BD"
               || name == "PH"
               || name == "WA"
               || name == "WD") { // Potion
      theDisplay[r][c] = 'P';
    } else if (name == "G") { // Normal Gold
      theDisplay[r][c] = 'G';
    } else if (name == "DH") { // Dragon hoard
      theDisplay[r][c] = 'G';
    } else if (name == "Stair"){ // Stair
      theDisplay[r][c] = '\\';
    } else { // Blank
      theDisplay[r][c] = ' ';
    }
  }
}

// addAction(act) adds act to this action
void TextDisplay::addAction(string act) {
  action = action + act;
}

// cleanAction() sets action to empty string
void TextDisplay::cleanAction() {
  action = "";
}

// operator<<(out, td) overloads the operator << so that
//   the entire grid is printed out when this operator
//   is invoked
// Effect: print output
ostream &operator<<(ostream &out, const TextDisplay &td) {
  for (int r = 0; r < td.rowSize; ++r) {
    for (int c = 0; c < td.colSize; ++c) {
      out << td.theDisplay[r][c];
    }
    out << endl;
  }
  string fst = "Race: " + td.player->getName()
                + " Gold: "
                + to_string(static_cast<int>(td.player->getGold()));
  out << fst
      << setw(75 - static_cast<int>(fst.length()))
      << "Floor " << td.floor->getLevel() << endl;
  out << "HP: " << static_cast<int>(td.player->getHp()) << endl;
  out << "Atk: " << static_cast<int>(td.player->getAtk()) << endl;
  out << "Def: " << static_cast<int>(td.player->getDef()) << endl;
  out << "Action: " << td.action << endl;
  return out;
}
