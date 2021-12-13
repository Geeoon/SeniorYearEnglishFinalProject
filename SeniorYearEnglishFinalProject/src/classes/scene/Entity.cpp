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

void Entity::move(Vector2 m) {
	Vector2 future{ position + m };

	if (!collision(future)) {
		position = future;
	}
}

bool Entity::collision(Vector2 pos) {
	bool output{ false };
	return output;
}