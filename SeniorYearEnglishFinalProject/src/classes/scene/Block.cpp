#include "Block.h"

Block::Block(float x, float y, Vector2 d = Vector2{ 10.0f, 10.0f }) : Object{ x, y }, dimentions { d } {

}

Block::Block(Vector2 pos, Vector2 d = Vector2{ 10.0f, 10.0f }) : Object{ pos }, dimentions{ d } {

}

void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

void Block::update(float elapsedTime) {

}