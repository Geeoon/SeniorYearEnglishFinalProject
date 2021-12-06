#include "Player.h"

Player::Player(float x, float y) : Entity{ x, y }, sprite{ sf::CircleShape{ 20.0f } } {
	sprite.setFillColor(sf::Color::Transparent);
	sprite.setOutlineColor(sf::Color::Green);
	sprite.setOutlineThickness(5);
	maxSpeed = 200.0f;
}

Player::Player(Vector2 vec) : Entity{ vec }, sprite{ sf::CircleShape{ 20.0f } } {
	sprite.setFillColor(sf::Color::Transparent);
	sprite.setOutlineColor(sf::Color::Green);
	sprite.setOutlineThickness(5);
	maxSpeed = 200.0f;
}

Player::~Player() {

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

void Player::update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		position -= Scene::elapsedTime.asSeconds() * maxSpeed * Vector2(0.0f, 1.0f);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		position += Scene::elapsedTime.asSeconds() * maxSpeed * Vector2(0.0f, 1.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		position += Scene::elapsedTime.asSeconds() * maxSpeed * Vector2(1.0f, 0.0f);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		position -= Scene::elapsedTime.asSeconds() * maxSpeed * Vector2(1.0f, 0.0f);
	}
	sprite.setPosition(position.x, position.y);
}