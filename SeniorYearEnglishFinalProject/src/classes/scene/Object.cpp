#include "Object.h"

Object::Object(float x, float y, std::shared_ptr<Level> l) : kill{ false }, position { Vector2{ x, y } }, level{ l } {

}

Object::Object(Vector2 pos, std::shared_ptr<Level> l) : kill{ false }, position { pos }, level{ l } {

}

Object::~Object() {

}

void Object::draw(sf::RenderTarget& target, sf::RenderStates states) const {

}

void Object::update(float elapsedTime) {

}

Vector2 Object::getPosition() const {
	return position;
}

void Object::setPosition(Vector2 p) {
	position = p;
}

bool Object::collided(const std::shared_ptr<Object> other) const {
	return false;
}

void Object::hurt(std::shared_ptr<Object> other) {

}

bool Object::neededForCompletion() {
	return false;
}

bool Object::getKill() {
	return kill;
}

void Object::damaged() {

}