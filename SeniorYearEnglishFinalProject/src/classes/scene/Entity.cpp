#include "Entity.h"

Entity::Entity(float x, float y) : Object{ Vector2{x, y} } {

}

Entity::Entity(Vector2 pos) : Object{ pos } {

}

Entity::~Entity() {

}