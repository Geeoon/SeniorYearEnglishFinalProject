#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "../physics/Vector.h"

class Entity : public Object {
public:
	Entity(float x, float y);
	Entity(Vector2 pos);
	~Entity();
	void setOrientation(float o);

protected:
	float maxSpeed{ 100.0f };
	float orientation{ 0.0f };
};