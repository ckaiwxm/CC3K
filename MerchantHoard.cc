#include "MerchantHoard.h"
#include "Tile.h"
#include "Player.h"

//Ctor
MerchantHoard::MerchantHoard(Tile* tile):
Gold(4, tile) {}

MerchantHoard::~MerchantHoard() {}
