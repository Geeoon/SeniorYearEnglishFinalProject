#pragma once
#include <SFML/Graphics.hpp>
#include "../physics/Vector.h"
#include "../scene/Scene.h"
#include "Entity.h"

class Player : public Entity {
public:
	Player(float x, float y);
	Player(Vector2 vec);
	~Player();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void update() override;

private:
	sf::CircleShape sprite;
};