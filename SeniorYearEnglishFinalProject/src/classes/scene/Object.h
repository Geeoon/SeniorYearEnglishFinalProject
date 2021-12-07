#pragma once
#include <SFML/Graphics.hpp>
#include "../physics/Vector.h"

class Object : public sf::Drawable {
public:
	Object(float x, float y);
	Object(Vector2 pos);
	~Object();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(float elapsedTime);
	Vector2 getPosition() const;

protected:
	Vector2 position;

};