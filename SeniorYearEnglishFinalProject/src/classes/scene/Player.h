#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <queue>
#include "../physics/Vector.h"
#include "level/Level.h"
#include "Dummy.h"
#include "Bullet.h"

class Player : public Dummy {
public:
	Player(float x, float y, std::queue<std::shared_ptr<Object>>& e, std::shared_ptr<Level> l);
	~Player();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void update(float elapsedTime) override;

protected:
	bool leftClickFlag{ false };
	sf::RectangleShape gunSprite;
	std::shared_ptr<Level> level;
};