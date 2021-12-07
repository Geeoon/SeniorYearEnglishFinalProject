#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Entity.h"
#include "Player.h"

class Scene : public sf::Drawable {
public:
	Scene();
	~Scene();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update(sf::Vector2i mouseLocation);

	inline static sf::Time elapsedTime;

private:
	sf::Clock clock;
	std::shared_ptr<Player> player;
	std::vector<std::shared_ptr<Entity>> entities;
};