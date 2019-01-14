#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
#include <iostream>
#include <vector>
class Tile;
class Floor;
class Player;

class TextDisplay {
  std::vector<std::vector<char>> theDisplay;
  const int colSize = 79;
  const int rowSize = 25;
  Player* player;
  Floor* floor;
  std::string action = "";
  
public:
  TextDisplay(Player* player, Floor* floor);
  ~TextDisplay();
  
  void notify(Tile* who);
  void addAction(std::string act);
  void cleanAction();
  friend std::ostream& operator << (std::ostream &out, const TextDisplay &td);
};

#endif
