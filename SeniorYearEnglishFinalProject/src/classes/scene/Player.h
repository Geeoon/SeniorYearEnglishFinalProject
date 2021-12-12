#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <queue>
#include "../physics/Vector.h"
#include "Dummy.h"
#include "Bullet.h"

class Player : public Dummy {
public:
	Player(float x, float y, std::queue<std::shared_ptr<Entity>>& e);
	Player(Vector2 vec, std::queue<std::shared_ptr<Entity>>& e);
	~Player();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void update(float elapsedTime) override;

protected:
	bool leftClickFlag{ false };
	sf::RectangleShape gunSprite;
};