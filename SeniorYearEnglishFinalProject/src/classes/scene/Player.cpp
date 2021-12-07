#include "Player.h"

Player::Player(float x, float y) : Dummy{ x, y }, gunSprite{ sf::RectangleShape{sf::Vector2f{ 5.0f, 15.0f } } } {
	sprite.setOutlineColor(sf::Color{ 0, 255, 65 });
	
	gunSprite.setFillColor(sf::Color{ 0, 255, 65 });
	gunSprite.setOrigin(gunSprite.getSize().x / 2.0f, -(sprite.getRadius() + 7.0f));
	maxSpeed = 200.0f;
	hp = 3;
}

Player::Player(Vector2 vec) : Dummy{ vec }, gunSprite{ sf::RectangleShape{sf::Vector2f{ 5.0f, 15.0f } } } {
	sprite.setOutlineColor(sf::Color{ 0, 255, 65 });

	gunSprite.setFillColor(sf::Color{ 0, 255, 65 });
	gunSprite.setOrigin(gunSprite.getSize().x / 2.0f, -(sprite.getRadius() + 7.0f));
	maxSpeed = 200.0f;
	hp = 3;
}

Player::~Player() {

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	Dummy::draw(target, states);
	target.draw(gunSprite);
}

void Player::update(float elapsedTime) {
	Dummy::update(elapsedTime);
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

	gunSprite.setPosition(position.x, position.y);
	gunSprite.setRotation(orientation - 90.0f);
}