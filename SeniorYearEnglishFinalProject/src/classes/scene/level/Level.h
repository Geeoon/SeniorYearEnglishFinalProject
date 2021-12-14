#pragma	once
#include <SFML/Graphics.hpp>
#include <map>
#include <utility>
#include "tile/WallTile.h"
#include "tile/Tile.h"

class Level : public sf::Drawable {
public:
	Level();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	std::shared_ptr<Tile> getTile(int x, int y) const;

private:
	std::map<std::pair<int, int>, std::shared_ptr<Tile>> tiles;
	std::shared_ptr<Tile> genericTile;
};