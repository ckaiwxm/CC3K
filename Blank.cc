#include "Blank.h"

using namespace std;

Blank::Blank(int col, int row, Floor* floor):
Tile(col, row, floor) {
  display = ' ';
}

Blank::~Blank() {}
