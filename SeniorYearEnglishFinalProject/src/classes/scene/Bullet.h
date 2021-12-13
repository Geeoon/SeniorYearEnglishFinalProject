#pragma once
#include "Entity.h"

class Bullet : public Entity {
public:
	Bullet(float x, float y, float o, std::shared_ptr<Level> l);
	Bullet(Vector2 pos, float o, std::shared_ptr<Level> l);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(float elapsedTime) override;
	virtual void move(Vector2 m) override;
	
protected:
	virtual bool collision(Vector2 pos) override;
	sf::RectangleShape sprite;
};