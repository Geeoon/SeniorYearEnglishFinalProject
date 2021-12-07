#include "Player.h"

Player::Player(float x, float y) : Entity{ x, y }, sprite{ sf::CircleShape{ 20.0f } }, gunSprite{ sf::RectangleShape{sf::Vector2f{ 5.0f, 15.0f } } } {
	sprite.setFillColor(sf::Color::Transparent);
	sprite.setOutlineColor(sf::Color::Green);
	sprite.setOutlineThickness(4);
	sprite.setOrigin(sprite.getRadius(), sprite.getRadius());

	gunSprite.setFillColor(sf::Color::Green);
	gunSprite.setOrigin(gunSprite.getSize().x / 2.0f, -(sprite.getRadius() + 7.0f));
	maxSpeed = 200.0f;
}

Player::Player(Vector2 vec) : Entity{ vec }, sprite{ sf::CircleShape{ 20.0f } }, gunSprite{ sf::RectangleShape{sf::Vector2f{ 5.0f, 15.0f } } } {
	sprite.setFillColor(sf::Color::Transparent);
	sprite.setOutlineColor(sf::Color{ 0, 255, 65 });
	sprite.setOutlineThickness(4);
	sprite.setOrigin(sprite.getRadius(), sprite.getRadius());

	gunSprite.setFillColor(sf::Color{ 0, 255, 65 });
	gunSprite.setOrigin(gunSprite.getSize().x / 2.0f, -(sprite.getRadius() + 7.0f));
	maxSpeed = 200.0f;
}

Player::~Player() {

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);

	target.draw(gunSprite);
}

void Player::update(float elapsedTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		position -= elapsedTime * maxSpeed * Vector2(0.0f, 1.0f);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		position += elapsedTime * maxSpeed * Vector2(0.0f, 1.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		position += elapsedTime * maxSpeed * Vector2(1.0f, 0.0f);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		position -= elapsedTime * maxSpeed * Vector2(1.0f, 0.0f);
	}

	sprite.setPosition(position.x, position.y);
	gunSprite.setPosition(position.x, position.y);
	gunSprite.setRotation(orientation - 90.0f);
}