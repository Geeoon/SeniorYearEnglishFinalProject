#pragma	once
#include "Tile.h"

class WallTile : public Tile {
public:
	WallTile(int x, int y);
	bool solid();

protected:

};