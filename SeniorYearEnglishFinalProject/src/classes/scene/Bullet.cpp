#include "Bullet.h"

Bullet::Bullet(float x, float y, float o, std::shared_ptr<Level> l) : Entity{ x, y, l }, sprite{ sf::RectangleShape{ sf::Vector2f{ 4.0f, 7.0f } } } {
	orientation = o;
	sprite.setFillColor(sf::Color{ 192, 192, 192 });
	sprite.setRotation(o - 90.0f);
	sprite.setOrigin(sprite.getSize() / 2.0f);

	maxSpeed = 1000.0f;
}

Bullet::Bullet(Vector2 pos, float o, std::shared_ptr<Level> l) : Entity{ pos, l }, sprite{ sf::RectangleShape{ sf::Vector2f{ 4.0f, 7.0f } } } {
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
	move(Vector2{ elapsedTime * maxSpeed * cos(orientation * 3.141593f / 180.0f), elapsedTime * maxSpeed * sin(orientation * 3.141593f / 180.0f) });
	sprite.setPosition(position.x, position.y);
}

void Bullet::move(Vector2 m) {
	Vector2 future{ position + m };

	if (!collision(future)) {
		position = future;
	} else {
		kill = true;
	}
}

void Bullet::hurt(std::shared_ptr<Object> other) {
	other->damaged();
	kill = true;
}

bool Bullet::collision(Vector2 pos) {
	bool output{ false };
	for (int c = 0; c < 4; c++) {
		Vector2 post{ pos.x + c % 2 * 0 - 0, pos.y + c / 2 * 0 - 0 };
		if (level->getTile(static_cast<int>(post.x / 40.0f), static_cast<int>(post.y / 40.0f))->solid()) {
			output = true;
			break;
		}
	}
	return output;
}