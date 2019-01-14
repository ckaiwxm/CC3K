#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Tile.h"

class Tile;

class Object {
protected:
  std::string name;
  Tile* tile;
  bool hasMoved = false;
  
public:
  // Big 5
  Object(std::string name, Tile* tile);
  virtual ~Object() = 0;
  
  // Get field
  Tile* getTile();
  std::string getName() const;
  bool getHasMoved() const;
  
  // Set field
  void setTile(Tile* newTile);
  void setHasMoved(bool newHasMoved);
};

#endif
