#include "WallTrigger.h"

WallTrigger::WallTrigger(float x, float y, std::shared_ptr<Level> l, Vector2 b, std::shared_ptr<Object> o, std::pair<int, int> t) : Trigger{ x, y, l, b, o }, tile{ t } {

}

WallTrigger::WallTrigger(Vector2 pos, std::shared_ptr<Level> l, Vector2 b, std::shared_ptr<Object> o, std::pair<int, int> t) : Trigger{ pos, l, b, o }, tile{ t } {

}

void WallTrigger::onTrigger() {
	if (level->getTile(tile.first, tile.second)->isEnabled()) {
		level->getTile(tile.first, tile.second)->changeEnabled(false);
	}
}