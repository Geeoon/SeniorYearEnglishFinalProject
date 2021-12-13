#include "Player.h"

Player::Player(float x, float y, std::queue<std::shared_ptr<Object>>& e, std::shared_ptr<Level> l) : Dummy{ x, y, e, l }, gunSprite{ sf::RectangleShape{sf::Vector2f{ 5.0f, 15.0f } } } {
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
	Vector2 movement{ 0.0f, 0.0f };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		movement -= elapsedTime * maxSpeed * Vector2(0.0f, 1.0f);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		movement += elapsedTime * maxSpeed * Vector2(0.0f, 1.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		movement += elapsedTime * maxSpeed * Vector2(1.0f, 0.0f);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		movement -= elapsedTime * maxSpeed * Vector2(1.0f, 0.0f);
	}

	if (movement.x != 0 && movement.y != 0) {
		move(Vector2{ movement.x, 0.0f });
		move(Vector2{ 0.0f, movement.y });
	} else {
		move(movement);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (!leftClickFlag) {
			leftClickFlag = true;
			objects.push(std::make_shared<Bullet>(position + Vector2{ cos(orientation * 3.141593f / 180.0f) * (sprite.getRadius() + 7.0f), sin(orientation * 3.141593f / 180.0f) * (sprite.getRadius() + 7.0f) }, orientation, level));
		}
	} else {
		leftClickFlag = false;
	}

	Dummy::update(elapsedTime);
	gunSprite.setPosition(position.x, position.y);
	gunSprite.setRotation(orientation - 90.0f);
}

void Player::move(Vector2 m) {
	Vector2 future{ position + m };

	if (!collision(future)) {
		position = future;
	}
}

bool Player::collision(Vector2 pos) {
	bool output{ false };
	for (int c = 0; c < 4; c++) {
		Vector2 post{ pos.x + c % 2 * 40 - 20, pos.y + c / 2 * 40 - 20 };
		if (level->getTile(static_cast<int>(post.x / 40.0f), static_cast<int>(post.y / 40.0f))->solid()) {
			output = true;
			break;
		}
	}
	
	return output;
}