#pragma once
#include "../physics/Vector.h"
#include "Entity.h"

class Dummy : public Entity {
public:
	Dummy(float x, float y);
	Dummy(Vector2 vec);
	~Dummy();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void update(float elapsedTime) override;

protected:
	sf::CircleShape sprite;

};