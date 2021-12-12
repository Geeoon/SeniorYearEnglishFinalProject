#include "Dummy.h"

Dummy::Dummy(float x, float y, std::queue<std::shared_ptr<Entity>>& e) : Entity{ x, y }, sprite{ sf::CircleShape{ 20.0f } }, entities{ e } {
	sprite.setFillColor(sf::Color::Transparent);
	sprite.setOutlineColor(sf::Color{ 100, 100, 100 });
	sprite.setOutlineThickness(4);
	sprite.setOrigin(sprite.getRadius(), sprite.getRadius());
}

Dummy::Dummy(Vector2 vec, std::queue<std::shared_ptr<Entity>>& e) : Entity{ vec }, sprite{ sf::CircleShape{ 20.0f } }, entities{ e } {
	sprite.setFillColor(sf::Color::Transparent);
	sprite.setOutlineColor(sf::Color{ 100, 100, 100 });
	sprite.setOutlineThickness(4);
	sprite.setOrigin(sprite.getRadius(), sprite.getRadius());
}

Dummy::~Dummy() {

}

void Dummy::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

void Dummy::update(float elapsedTime) {
	sprite.setPosition(position.x, position.y);
}