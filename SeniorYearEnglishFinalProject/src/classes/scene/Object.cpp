#include "Object.h"

Object::Object(float x, float y, std::shared_ptr<Level> l) : position{ Vector2{x, y} }, level{ l } {

}

Object::Object(Vector2 pos, std::shared_ptr<Level> l) : position{ pos }, level{ l } {

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

bool Object::collided(const Object& other) {
	return false;
}

bool Object::hurt() {
	return false;
}