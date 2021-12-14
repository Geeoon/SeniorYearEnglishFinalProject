#include "Dummy.h"

Dummy::Dummy(float x, float y, std::queue<std::shared_ptr<Object>>& e, std::shared_ptr<Level> l) : Entity{ x, y, l }, sprite{ sf::CircleShape{ 20.0f } }, objects{ e }, hpIndicator{ 0.0f, 0.0f, l, 13, "HP: " } {
	sprite.setFillColor(sf::Color::Transparent);
	sprite.setOutlineColor(sf::Color{ 100, 100, 100 });
	sprite.setOutlineThickness(3.0f);
	sprite.setOrigin(sprite.getRadius(), sprite.getRadius());
}

Dummy::Dummy(Vector2 vec, std::queue<std::shared_ptr<Object>>& e, std::shared_ptr<Level> l) : Entity{ vec, l }, sprite{ sf::CircleShape{ 20.0f } }, objects{ e }, hpIndicator{ 0.0f, 0.0f, l, 13, "HP: " } {
	sprite.setFillColor(sf::Color::Transparent);
	sprite.setOutlineColor(sf::Color{ 100, 100, 100 });
	sprite.setOutlineThickness(3.0f);
	sprite.setOrigin(sprite.getRadius(), sprite.getRadius());
}

Dummy::~Dummy() {

}

void Dummy::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
	target.draw(hpIndicator);
}

void Dummy::update(float elapsedTime) {
	sprite.setPosition(position.x, position.y);
	hpIndicator.setPosition(position - Vector2{ 0.0f, 40.0f });
	hpIndicator.setText("HP: " + std::to_string(hp));
	hpIndicator.update(elapsedTime);
}

void Dummy::move(Vector2 m) {
	Vector2 future{ position + m };
	if (m.x != 0 && m.y != 0) {
		move(Vector2{ m.x, 0.0f });
		move(Vector2{ 0.0f, m.y });
	} else {
		if (!collision(future)) {
			position = future;
		}
	}
}

bool Dummy::collided(const std::shared_ptr<Object> other) const {
	Vector2 delta{other->getPosition() - position};
	return delta.magnitude() < sprite.getRadius();
}

void Dummy::damaged() {
	hp--;
	if (hp < 1) {
		kill = true;
	}
}

void Dummy::hurt(std::shared_ptr<Object> other) {

}

bool Dummy::collision(Vector2 pos) {
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