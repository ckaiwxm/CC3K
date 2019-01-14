#include "VWall.h"

using namespace std;

VWall::VWall(int col, int row, Floor* floor):
Tile(col, row, floor) {
  display = '|';
}

VWall::~VWall() {}
