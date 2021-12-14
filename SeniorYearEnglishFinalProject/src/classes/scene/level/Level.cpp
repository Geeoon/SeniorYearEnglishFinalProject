#include "Level.h"

Level::Level() : genericTile{ std::make_shared<Tile>(0, 0) } {
    int x = 50;
    int y = 30;
    for (int i = 2; i < x; i++) {
        tiles.insert(std::make_pair<std::pair<int, int>, std::shared_ptr<Tile>>(std::pair<int, int>{ i, 2 }, std::make_shared<WallTile>(i, 2)));
        tiles.insert(std::make_pair<std::pair<int, int>, std::shared_ptr<Tile>>(std::pair<int, int>{ i, y }, std::make_shared<WallTile>(i, y)));
    }

    for (int i = 2; i < y / 2; i++) {
        tiles.insert(std::make_pair<std::pair<int, int>, std::shared_ptr<Tile>>(std::pair<int, int>{ x / 2, i }, std::make_shared<WallTile>(x / 2, i)));
    }

    for (int i = 2; i < y + 1; i++) {
        tiles.insert(std::make_pair<std::pair<int, int>, std::shared_ptr<Tile>>(std::pair<int, int>{ 2, i }, std::make_shared<WallTile>(2, i)));
        tiles.insert(std::make_pair<std::pair<int, int>, std::shared_ptr<Tile>>(std::pair<int, int>{ x, i }, std::make_shared<WallTile>(x, i)));
    }

    for () {

    }
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

std::vector<std::shared_ptr<Object>>& Level::getTriggers() {
    return triggers;
}