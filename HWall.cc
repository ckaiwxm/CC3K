#include "HWall.h"

using namespace std;

HWall::HWall(int col, int row, Floor* floor):
Tile(col, row, floor) {
  display = '-';
}

HWall::~HWall() {}
