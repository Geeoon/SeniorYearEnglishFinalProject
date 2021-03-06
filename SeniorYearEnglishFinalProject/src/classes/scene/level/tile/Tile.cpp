#include "Tile.h"

Tile::Tile(int xa, int ya) : x{ xa }, y{ ya }, enabled{ false } {
	sprite.setPosition(static_cast<float>(x) * dimensions.x, static_cast<float>(y) * dimensions.y);
	sprite.setSize(sf::Vector2f{ dimensions.x, dimensions.y });
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

bool Tile::isEnabled() {
	return enabled;
}

void Tile::changeEnabled(bool b) {
	if (enabled == true && b == false) {
		sprite.setOutlineColor(sf::Color{ static_cast<sf::Uint8>(sprite.getOutlineColor().r / 2), static_cast<sf::Uint8>(sprite.getOutlineColor().g / 2), static_cast<sf::Uint8>(sprite.getOutlineColor().b / 2) });
	} else if (enabled == false) {																				   
		sprite.setOutlineColor(sf::Color{ static_cast<sf::Uint8>(sprite.getOutlineColor().r * 2), static_cast<sf::Uint8>(sprite.getOutlineColor().g * 2), static_cast<sf::Uint8>(sprite.getOutlineColor().b * 2) });
	}
	enabled = b;
}