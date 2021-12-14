#include "Trigger.h"

Trigger::Trigger(float x, float y, std::shared_ptr<Level> l, Vector2 b, std::shared_ptr<Object> o) : Entity{ x, y, l }, object{ o }, bounds{ b } {
	testSprite.setPosition(x, y);
	testSprite.setSize(sf::Vector2f{ b.x, b.y });
	testSprite.setOrigin(sf::Vector2f{ 0.0f, 0.0f });
	testSprite.setFillColor(sf::Color{ 0, 0, 255, 010 });
	testSprite.setOutlineThickness(0.0f);
}

Trigger::Trigger(Vector2 pos, std::shared_ptr<Level> l, Vector2 b, std::shared_ptr<Object> o) : Entity{ pos, l }, object{ o }, bounds{ b } {
	testSprite.setPosition(static_cast<float>(pos.x), static_cast<float>(pos.y));
	testSprite.setSize(sf::Vector2f{ b.x, b.y });
	testSprite.setOrigin(sf::Vector2f{ 0.0f, 0.0f });
	testSprite.setFillColor(sf::Color{ 0, 0, 255, 010 });
	testSprite.setOutlineThickness(0.0f);
}

void Trigger::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(testSprite);
}

void Trigger::update(float elapsedTime) {
	if (object->getPosition().x > position.x && object->getPosition().x < bounds.x + position.x && object->getPosition().y > position.y && object->getPosition().y < bounds.y + position.y) {
		onTrigger();
	}
}

void Trigger::onTrigger() {

}