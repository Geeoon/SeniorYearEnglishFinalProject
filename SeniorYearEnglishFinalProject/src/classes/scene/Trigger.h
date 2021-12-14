#pragma once
#include <iostream>
#include "Entity.h"
#include "../physics/Vector.h"

class Trigger : public Entity {
public:
	Trigger(float x, float y, std::shared_ptr<Level> l, Vector2 b, std::shared_ptr<Object> o);
	Trigger(Vector2 pos, std::shared_ptr<Level> l, Vector2 b, std::shared_ptr<Object> o);
	~Trigger() = default;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void update(float elapsedTime) override;
	virtual void onTrigger();

protected:
	std::shared_ptr<Object> object;
	Vector2 bounds;

	sf::RectangleShape testSprite;
};