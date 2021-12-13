#include "Entity.h"

Entity::Entity(float x, float y, std::shared_ptr<Level> l) : Object{ Vector2{x, y}, l } {

}

Entity::Entity(Vector2 pos, std::shared_ptr<Level> l) : Object{ pos, l } {

}

Entity::~Entity() {

}

void Entity::setOrientation(float o) {
	orientation = o;
}