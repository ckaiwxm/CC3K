#include "Door.h"

using namespace std;

Door::Door(int col, int row, Floor* floor):
Tile(col, row, floor) {
  display = '+';
}

Door::~Door() {}
