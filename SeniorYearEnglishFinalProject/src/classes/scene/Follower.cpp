#include "Follower.h"

Follower::Follower(float x, float y, std::queue<std::shared_ptr<Object>>& e, std::shared_ptr<Level> l, std::shared_ptr<Object> f) : Dummy{ x, y, e, l }, follow{ f } {
	sprite.setOutlineColor(sf::Color::Red);
}

Follower::Follower(Vector2 pos, std::queue<std::shared_ptr<Object>>& e, std::shared_ptr<Level> l, std::shared_ptr<Object> f) : Dummy{ pos, e, l }, follow{ f } {
	sprite.setOutlineColor(sf::Color::Red);
}

Follower::~Follower() {

}

void Follower::update(float elapsedTime) {
	Vector2 deltaP{ follow->getPosition() - position };
	float ratio{ maxSpeed * MathHelper::calcInvSqrtFast(deltaP.x * deltaP.x + deltaP.y * deltaP.y) };
	move(ratio * elapsedTime * deltaP);
	Dummy::update(elapsedTime);
}

void Follower::hurt(std::shared_ptr<Object> other) {
	other->damaged();
}