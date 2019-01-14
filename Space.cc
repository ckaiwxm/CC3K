#include "Space.h"

using namespace std;

Space::Space(int col, int row, Floor* floor):
Tile(col, row, floor) {
  display = '.';
}

Space::~Space() {}
