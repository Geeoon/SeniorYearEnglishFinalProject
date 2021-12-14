#pragma once
#include <SFML/Graphics.hpp>
#include "../../../physics/Vector.h"

class Tile : public sf::Drawable{
public:
	Tile(int xa, int ya);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual bool solid();
	virtual bool isEnabled();
	void changeEnabled(bool b);

protected:
	int x, y;
	bool enabled;
	Vector2 position;
	sf::RectangleShape sprite;
	const Vector2 dimensions{ 40.0f, 40.0f };
};