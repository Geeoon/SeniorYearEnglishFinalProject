#include "Object.h"

Object::Object(float x, float y) : position{ Vector2{x, y} } {

}

Object::Object(Vector2 pos) : position{ pos } {

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