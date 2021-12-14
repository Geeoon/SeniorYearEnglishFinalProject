#pragma once
#include <queue>
#include "../physics/Vector.h"
#include "Entity.h"

class Dummy : public Entity {
public:
	Dummy(float x, float y, std::queue<std::shared_ptr<Object>>& e, std::shared_ptr<Level> l);
	Dummy(Vector2 vec, std::queue<std::shared_ptr<Object>>& e, std::shared_ptr<Level> l);
	~Dummy();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void update(float elapsedTime) override;
	virtual void move(Vector2 m) override;

protected:
	virtual bool collision(Vector2 pos) override;
	sf::CircleShape sprite;
	std::queue<std::shared_ptr<Object>>& objects;
};