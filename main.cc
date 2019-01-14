#include <iostream>
#include <fstream>
#include <iomanip>
#include <memory>
#include <string>
#include <ctime>
#include <cstdlib>

// Bases
#include "Floor.h"
#include "Tile.h"
#include "TextDisplay.h"
#include "Object.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Gold.h"
#include "Potion.h"

using namespace std;

bool game() {
  string cmd;
  string race = "s";
  Floor f;
  Player* p;

  cout << "Welcome to the game of Chamber Crawler 3000 (^_^)" << endl;
  cout << "Do you want to choose a race?(y/n)" << endl;
  cin >> cmd;
  if (cmd == "y") { // Yes, want to choose race
    cout << "Please enter a race: " << endl;
    
    while (true) { // Race selection loop
      cin >> race;
      if (race == "s") {
        p = new Shade();
      } else if (race == "d") {
        p = new Drow();
      } else if (race == "v") {
        p = new Vampire();
      } else if (race == "t") {
        p = new Troll();
      } else if (race == "g") {
        p = new Goblin();
      } else {
        p = nullptr;
      }
      if (p == nullptr) {
        cout << "Please enter again: " << endl;
      } else {
        break;
      }
    }
  } else { // No, Shade
    p = new Shade();
  }
  
  f.init(p);
  cout << f;
  
  try {
    
    while (true) {
      
      if (f.getLevel() >= 6) { // Win
        cout << "Congratulations! You win!" << endl;
        double score = p->getGold();
        if (race == "s") {
          score = score * 1.50;
        }
        cout << static_cast<int>(score) << " golden geese will be shipped to your home address after the summer vacation. " << endl;
        cout << "Do you want to restart? (y/n)" << endl;
        cin >> cmd;
        if (cmd == "y") {
          return true;
        } else {
          return false;
        }
      }
      
      if (p->getHp() <= 0) { // Lose
        cout << "R.I.P. Welcome to the hell of CS246!" << endl;
        cout << "Do you want to restart? (y/n)" << endl;
        cin >> cmd;
        if (cmd == "y") {
          return true;
        } else {
          return false;
        }
      }
      
      f.clearTextDisplay();
      cin >> cmd;
        
      if (cmd == "r") {
        return true;
       }
        
      else if (cmd == "q") {
        return false;
      }
        
      else if (cmd == "f") {
        f.changeFreezeState();
      }
        
      else if (cmd == "no"
          || cmd == "so"
          || cmd == "ea"
          || cmd == "we"
          || cmd == "ne"
          || cmd == "nw"
          || cmd == "se"
          || cmd == "sw") {
        if (f.pMoveTo(cmd) == false) {
          cin.ignore();
          cin.clear();
          cout << "Unable to move. Please enter again: " << endl;
          continue;
        }
        cout << f;
      }
        
      else if (cmd == "u") {
        cin >> cmd;
        if (cmd == "no"
            || cmd == "so"
            || cmd == "ea"
            || cmd == "we"
            || cmd == "ne"
            || cmd == "nw"
            || cmd == "se"
            || cmd == "sw") {
          if (f.pPotion(cmd) == false) {
            cin.ignore();
            cin.clear();
            cout << "Unable to use potion. Please enter again: " << endl;
            continue;
          }
          cout << f;
        } else {
          cout << "Wrong use direction input. Please enter again: " << endl;
          continue;
        }
      }
        
      else if (cmd == "a") {
        cin >> cmd;
        if (cmd == "no"
            || cmd == "so"
            || cmd == "ea"
            || cmd == "we"
            || cmd == "ne"
            || cmd == "nw"
            || cmd == "se"
            || cmd == "sw") {
          if (f.pAttack(cmd) == false) {
            cin.ignore();
            cin.clear();
            cout << "Unable to attack. Please enter again: " << endl;
            continue;
          }
          cout << f;
        } else {
          cout << "Wrong attack direction input. Please enter again: " << endl;
          continue;
        }
      }
        
      else {
        cin.ignore();
        cin.clear();
        continue;
      }
    }
  } catch (...) {
    cerr << "ERR: something wrong" << endl;
  }
  return false;
}
          
int main() {
  srand((unsigned)time(NULL));
  bool ifRestart = true;
  while (ifRestart == true) {
    ifRestart = game();
  }
  return 0;
}

