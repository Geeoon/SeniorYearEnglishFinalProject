#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "../physics/Vector.h"

class Entity : public Object {
public:
	Entity(float x, float y, std::shared_ptr<Level> l);
	Entity(Vector2 pos, std::shared_ptr<Level> l);
	~Entity();
	void setOrientation(float o);
	virtual void move(Vector2 m);

protected:
	virtual bool collision(Vector2 pos);
	float maxSpeed{ 100.0f };
	float orientation{ 0.0f };
	int hp{ 1 };
};