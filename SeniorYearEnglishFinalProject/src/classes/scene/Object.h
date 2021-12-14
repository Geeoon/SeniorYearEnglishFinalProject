#pragma once
#include <SFML/Graphics.hpp>
#include "level/Level.h"
#include "../physics/Vector.h"

class Object : public sf::Drawable {
public:
	Object(float x, float y, std::shared_ptr<Level> l);
	Object(Vector2 pos, std::shared_ptr<Level> l);
	~Object();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(float elapsedTime);
	Vector2 getPosition() const;
	virtual void setPosition(Vector2 p);
	virtual bool collided(const Object& other);
	virtual bool hurt();
	bool getKill();

protected:
	bool kill;
	Vector2 position;
	std::shared_ptr<Level> level;
};