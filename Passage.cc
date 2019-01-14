#include "Passage.h"

using namespace std;

Passage::Passage(int col, int row, Floor* floor):
Tile(col, row, floor) {
  display = '#';
}

Passage::~Passage() {}
