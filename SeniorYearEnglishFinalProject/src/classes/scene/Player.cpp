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

	for (auto entity : entities) {
		target.draw(*entity);
	}
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

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (!leftClickFlag) {
			leftClickFlag = true;
			entities.push_back(std::make_shared<Bullet>(position + Vector2{ cos(orientation * 3.141593f / 180.0f) * (sprite.getRadius() + 7.0f), sin(orientation * 3.141593f / 180.0f) * (sprite.getRadius() + 7.0f) }, orientation));
		}
	} else {
		leftClickFlag = false;
	}

	Dummy::update(elapsedTime);
	gunSprite.setPosition(position.x, position.y);
	gunSprite.setRotation(orientation - 90.0f);

	for (auto entity : entities) {
		entity->update(elapsedTime);
	}
}