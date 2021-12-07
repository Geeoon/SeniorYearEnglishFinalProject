#include "Bullet.h"

Bullet::Bullet(float x, float y, float o) : Entity{ x, y }, sprite{ sf::RectangleShape{ sf::Vector2f{ 4.0f, 7.0f } } } {
	orientation = o;
	sprite.setFillColor(sf::Color{ 192, 192, 192 });
	sprite.setRotation(o - 90.0f);
	sprite.setOrigin(sprite.getSize() / 2.0f);

	maxSpeed = 1000.0f;
}

Bullet::Bullet(Vector2 pos, float o) : Entity{ pos }, sprite{ sf::RectangleShape{ sf::Vector2f{ 4.0f, 7.0f } } } {
	orientation = o;
	sprite.setFillColor(sf::Color{ 192, 192, 192 });
	sprite.setRotation(o - 90.0f);
	sprite.setOrigin(sprite.getSize() / 2.0f);

	maxSpeed = 1000.0f;
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

void Bullet::update(float elapsedTime) {
	position += Vector2{ elapsedTime * maxSpeed * cos(orientation * 3.141593f / 180.0f), elapsedTime * maxSpeed * sin(orientation * 3.141593f / 180.0f) };
	sprite.setPosition(position.x, position.y);
}