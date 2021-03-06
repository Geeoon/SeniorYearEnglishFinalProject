#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <queue>
#include "Text.h"
#include "WallTrigger.h"
#include "Trigger.h"
#include "Follower.h"
#include "level/Level.h"
#include "Entity.h"
#include "Dummy.h"
#include "Player.h"

class Scene : public sf::Drawable {
public:
	Scene();
	~Scene();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update(sf::Vector2i mouseLocation);
	std::shared_ptr<Player> getPlayer() const;
	int getDone();

	inline static sf::Time elapsedTime;

private:
	int done{ 0 };
	sf::Clock clock;
	std::shared_ptr<Player> player;
	std::vector<std::shared_ptr<Object>> objects;
	std::queue<std::shared_ptr<Object>> objectsQueue;
	std::shared_ptr<Level> level;
};