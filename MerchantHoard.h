#ifndef _MERCHANTHOARD_H_
#define _MERCHANTHOARD_H_

#include "Gold.h"

class MerchantHoard:public Gold {
public:
  MerchantHoard(Tile* tile);
  ~MerchantHoard();
};

#endif
