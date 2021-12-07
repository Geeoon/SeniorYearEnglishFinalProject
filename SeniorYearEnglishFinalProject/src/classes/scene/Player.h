#pragma once
#include <SFML/Graphics.hpp>
#include "../physics/Vector.h"
#include "Entity.h"

class Player : public Entity {
public:
	Player(float x, float y);
	Player(Vector2 vec);
	~Player();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void update(float elapsedTime) override;

private:
	sf::CircleShape sprite;
	sf::RectangleShape gunSprite;
};