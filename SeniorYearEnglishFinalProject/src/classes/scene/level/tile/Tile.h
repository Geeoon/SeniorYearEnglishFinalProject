#pragma once
#include <SFML/Graphics.hpp>
#include "../../../physics/Vector.h"

class Tile : public sf::Drawable{
public:
	Tile(int xa, int ya);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual bool solid();

protected:
	int x, y;
	Vector2 position;
	sf::RectangleShape sprite;
	const Vector2 dimensions{ 40.0f, 40.0f };
};