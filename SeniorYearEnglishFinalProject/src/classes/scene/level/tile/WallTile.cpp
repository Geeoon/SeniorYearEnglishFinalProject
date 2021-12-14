#include "WallTile.h"

WallTile::WallTile(int x, int y) : Tile{ x, y } {
	enabled = true;
}

bool WallTile::solid() {
	return enabled;
}