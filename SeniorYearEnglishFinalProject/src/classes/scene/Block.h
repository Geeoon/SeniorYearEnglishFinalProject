#pragma once
#include <SFML/Graphics.hpp>
#include "../physics/Vector.h"
#include "Object.h"

class Block : public Object {
public:
	Block(float x, float y, Vector2 d = Vector2{ 10.0f, 10.0f });
	Block(Vector2 pos, Vector2 d = Vector2{ 10.0f, 10.0f });
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void update(float elapsedTime) override;

protected:
	sf::RectangleShape sprite;
	Vector2 dimentions;
};