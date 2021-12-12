#pragma once
#include <queue>
#include "../physics/Vector.h"
#include "Entity.h"

class Dummy : public Entity {
public:
	Dummy(float x, float y, std::queue<std::shared_ptr<Object>>& e);
	Dummy(Vector2 vec, std::queue<std::shared_ptr<Object>>& e);
	~Dummy();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void update(float elapsedTime) override;

protected:
	sf::CircleShape sprite;
	std::queue<std::shared_ptr<Object>>& objects;
};