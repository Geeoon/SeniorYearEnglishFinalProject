#include "Tile.h"

Tile::Tile(int xa, int ya) : x{ xa }, y{ ya } {
	sprite.setPosition(static_cast<float>(x) * dimensions.x, static_cast<float>(y) * dimensions.y);
	sprite.setSize(sf::Vector2f{ dimensions.x, dimensions.y });
	//sprite.setOrigin(sprite.getSize() / 2.0f);
	sprite.setOrigin(sf::Vector2f{ 0.0f, 0.0f });
	sprite.setFillColor(sf::Color::Transparent);
	sprite.setOutlineThickness(2.0f);
}
void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

bool Tile::solid() {
	return false;
}