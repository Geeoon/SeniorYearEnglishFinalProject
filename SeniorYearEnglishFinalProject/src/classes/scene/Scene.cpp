#include "Scene.h"

Scene::Scene() {
	level = std::make_shared<Level>();
	player = std::make_shared<Player>(260.0f, 150.0f, objectsQueue, level);
	objects.push_back(player);
	objects.push_back(std::make_shared<Follower>(880.0f, 480.0f, objectsQueue, level, player));
	objects.push_back(std::make_shared<WallTrigger>(1100.0f, 120.0f, level, Vector2{ 20.0f, 680.0f }, player, std::pair<int, int>{ 20, 10 }));
	objects.push_back(std::make_shared<WallTrigger>(1100.0f, 120.0f, level, Vector2{ 20.0f, 680.0f }, player, std::pair<int, int>{ 21, 10 }));
	objects.push_back(std::make_shared<WallTrigger>(1100.0f, 120.0f, level, Vector2{ 20.0f, 680.0f }, player, std::pair<int, int>{ 22, 10 }));
	objects.push_back(std::make_shared<WallTrigger>(1100.0f, 120.0f, level, Vector2{ 20.0f, 680.0f }, player, std::pair<int, int>{ 23, 10 }));
	objects.push_back(std::make_shared<WallTrigger>(1100.0f, 120.0f, level, Vector2{ 20.0f, 680.0f }, player, std::pair<int, int>{ 20, 11 }));
	objects.push_back(std::make_shared<WallTrigger>(1100.0f, 120.0f, level, Vector2{ 20.0f, 680.0f }, player, std::pair<int, int>{ 23, 11 }));
	objects.push_back(std::make_shared<WallTrigger>(1100.0f, 120.0f, level, Vector2{ 20.0f, 680.0f }, player, std::pair<int, int>{ 20, 12 }));
	objects.push_back(std::make_shared<WallTrigger>(1100.0f, 120.0f, level, Vector2{ 20.0f, 680.0f }, player, std::pair<int, int>{ 23, 12 }));
	objects.push_back(std::make_shared<WallTrigger>(1100.0f, 120.0f, level, Vector2{ 20.0f, 680.0f }, player, std::pair<int, int>{ 20, 13 }));
	objects.push_back(std::make_shared<WallTrigger>(1100.0f, 120.0f, level, Vector2{ 20.0f, 680.0f }, player, std::pair<int, int>{ 21, 13 }));
	objects.push_back(std::make_shared<WallTrigger>(1100.0f, 120.0f, level, Vector2{ 20.0f, 680.0f }, player, std::pair<int, int>{ 22, 13 }));
	objects.push_back(std::make_shared<WallTrigger>(1100.0f, 120.0f, level, Vector2{ 20.0f, 680.0f }, player, std::pair<int, int>{ 23, 13 }));
	objects.push_back(std::make_shared<Text>(260.0f, 0.0f, level, 24, "Welcome."));
	objects.push_back(std::make_shared<Text>(260.0f, 200.0f, level, 12, "To move, use the [W] [A] [S] [D] keys."));
	objects.push_back(std::make_shared<Text>(425.0f, 450.0f, level, 12, "These white boxes around you are firewalls,\nyou cannot pass through them."));
	objects.push_back(std::make_shared<Text>(800.0f, 600.0f, level, 12, "That red sphere that's trapped is a virus,\nit will attempt to infect you, do not let it get too close or you may die."));
	objects.push_back(std::make_shared<Text>(900.0f, 300.0f, level, 12, "This blue rectangle is a trigger,\nupon being activated, sections of the level may change."));
	objects.push_back(std::make_shared<Text>(1600.0f, 300.0f, level, 12, "Looks like this trigger released the virus!\nuse your gun to shoot the virus!"));
}

Scene::~Scene() {

}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*level);
	std::for_each(objects.begin(), objects.end(), [&](std::shared_ptr<Object> e) { target.draw(*e); });
}

void Scene::update(sf::Vector2i mouseLocation) {
	// have the dummies come towards the player and chase them.
	// Have text at the beginning that describes the world.

	elapsedTime = clock.getElapsedTime();
	clock.restart();

	player->setOrientation(atan2f(mouseLocation.y - player->getPosition().y, mouseLocation.x - player->getPosition().x) * 180.0f / 3.141593f);

	// general updates to all entities
	std::for_each(objects.begin(), objects.end(), [&](std::shared_ptr<Object> e) { e->update(elapsedTime.asSeconds()); });

	// update queued entities and push them into the main vector
	
	while (!objectsQueue.empty()) {
		objects.push_back(objectsQueue.front());
		objectsQueue.front()->update(elapsedTime.asSeconds());
		objectsQueue.pop();
	}	
	

	// check for collisions between objects
	for (auto i = objects.begin(); i != objects.end(); ++i) {
		for (auto j = objects.begin(); j != objects.end(); ++j) {
			if (*i != *j) {
				if ((*i)->collided(*j)) {
					(*j)->hurt(*i);
				}
			}
		}
	}

	int num{ 0 };
	for (auto i = objects.begin(); i != objects.end(); ++i) {
		if ((*i)->neededForCompletion()) {
			num++;
		}
	}

	if (player->getKill() == true) {
		done = 2;
	}

	if (num == 1) {
		done = 1;
	}

	// iterate and kill objects with getKill() == true
	for (auto i = objects.begin(); i != objects.end();) {
		if ((*i)->getKill()) {
			i = objects.erase(i);
		} else {
			++i;
		}
	}
}

std::shared_ptr<Player> Scene::getPlayer() const {
	return player;
}

int Scene::getDone() {
	return done;
}