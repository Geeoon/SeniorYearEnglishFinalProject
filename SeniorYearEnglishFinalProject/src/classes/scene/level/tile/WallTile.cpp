#include "WallTile.h"

WallTile::WallTile(int x, int y) : Tile{ x, y } {
}

bool WallTile::solid() {
	return true;
}