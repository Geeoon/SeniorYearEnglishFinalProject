#include "Level.h"

Level::Level() : genericTile{ std::make_shared<Tile>(0, 0) } {
    tiles.insert(std::make_pair<std::pair<int, int>, std::shared_ptr<Tile >>(std::pair<int, int>{ 0, 0 }, std::make_shared<WallTile>(0, 0)));
    tiles.insert(std::make_pair<std::pair<int, int>, std::shared_ptr<Tile >>(std::pair<int, int>{ 1, 0 }, std::make_shared<WallTile>(1, 0)));
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (auto& t : tiles) {
        target.draw(*(t.second));
    }
}

std::shared_ptr<Tile> Level::getTile(int x, int y) const {
    
    std::map<std::pair<int, int>, std::shared_ptr<Tile>>::const_iterator got = tiles.find(std::pair<int, int>{ x, y });
    if (got == tiles.end()) {
        return genericTile;
    } else {
        return got->second;
    }
}