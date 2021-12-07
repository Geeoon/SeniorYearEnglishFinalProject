#include "Player.h"

Player::Player(float x, float y) : Entity{ x, y }, sprite{ sf::CircleShape{ 20.0f } }, gunSprite{ sf::RectangleShape{sf::Vector2f{ 10.0f, 20.0f } } } {
	sprite.setFillColor(sf::Color::Transparent);
	sprite.setOutlineColor(sf::Color::Green);
	sprite.setOutlineThickness(5);

	gunSprite.setFillColor(sf::Color::Green);
	gunSprite.setOrigin(gunSprite.getSize().x / 2.0f, sprite.getRadius() + 2.0f);
	maxSpeed = 200.0f;
}

Player::Player(Vector2 vec) : Entity{ vec }, sprite{ sf::CircleShape{ 20.0f } }, gunSprite{ sf::RectangleShape{sf::Vector2f{ 10.0f, 20.0f } } } {
	sprite.setFillColor(sf::Color::Transparent);
	sprite.setOutlineColor(sf::Color{ 0, 255, 65 });
	sprite.setOutlineThickness(5);

	gunSprite.setFillColor(sf::Color{ 0, 255, 65 });
	maxSpeed = 200.0f;
}

Player::~Player() {

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);

	target.draw(gunSprite);
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

	float playerToCursorAngle{ atan2f(position.y - sf::Mouse::getPosition(sf::RenderWindow).y, position.x - sf::Mouse::getPosition().x) };

	sprite.setPosition(position.x, position.y);
	gunSprite.setPosition(position.x + sprite.getRadius(), position.y + sprite.getRadius());
	gunSprite.setRotation(playerToCursorAngle * 180.0f / 3.141592f);
}