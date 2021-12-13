#include "Level.h"

Level::Level() : genericTile{ std::make_shared<Tile>(0, 0) } {
    for (int i = 0; i < 30; i++) {
        //tiles.insert(std::make_pair<std::pair<int, int>, std::shared_ptr<Tile >>(std::pair<int, int>{ i, 0 }, std::make_shared<WallTile>(i, 0)));
        //tiles.insert(std::make_pair<std::pair<int, int>, std::shared_ptr<Tile >>(std::pair<int, int>{ 0, i + 1 }, std::make_shared<WallTile>(0, i + 1)));

        //tiles.insert(std::make_pair<std::pair<int, int>, std::shared_ptr<Tile >>(std::pair<int, int>{ 0, i * 3 }, std::make_shared<WallTile>(0, i * 3)));
        //tiles.insert(std::make_pair<std::pair<int, int>, std::shared_ptr<Tile >>(std::pair<int, int>{ i + 1, 30 }, std::make_shared<WallTile>(i + 1, 30)));
    }
    tiles.insert(std::make_pair<std::pair<int, int>, std::shared_ptr<Tile >>(std::pair<int, int>{ 0, 2 }, std::make_shared<WallTile>(0, 2)));


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