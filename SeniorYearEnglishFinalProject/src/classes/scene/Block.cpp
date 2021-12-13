#include "Block.h"

Block::Block(float x, float y, Vector2 d) : Object{ x, y }, dimentions { d } {
	sprite.setOrigin(sf::Vector2f{ 0.0f, 0.0f });
	sprite.setPosition(x, y);
	sprite.setSize(sf::Vector2f{ d.x, d.y });
	sprite.setFillColor(sf::Color::Transparent);
	sprite.setOutlineColor(sf::Color::Blue);
	sprite.setOutlineThickness(2.0f);
}

Block::Block(Vector2 pos, Vector2 d) : Object{ pos }, dimentions{ d } {
	sprite.setOrigin(sf::Vector2f{ 0.0f, 0.0f });
	sprite.setPosition(pos.x, pos.y);
	sprite.setSize(sf::Vector2f{ d.x, d.y });
	sprite.setFillColor(sf::Color::Transparent);
	sprite.setOutlineColor(sf::Color::Blue);
	sprite.setOutlineThickness(2.0f);
}

void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

void Block::update(float elapsedTime) {

}