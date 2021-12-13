#include "Scene.h"

Scene::Scene() {
	level = std::make_shared<Level>();
	player = std::make_shared<Player>(100.0f, 100.0f, objectsQueue, level);
	objects.push_back(player);
	objects.push_back(std::make_shared<Dummy>(200.0f, 200.0f, objectsQueue, level));
}

Scene::~Scene() {

}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*level);
	std::for_each(objects.begin(), objects.end(), [&](std::shared_ptr<Object> e) { target.draw(*e); });
}

void Scene::update(sf::Vector2i mouseLocation) {
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
	for (std::vector<std::shared_ptr<Object>>::iterator i = objects.begin(); i != objects.end() - 1; ++i) {
		for (std::vector<std::shared_ptr<Object>>::iterator j = i + 1; j != objects.end(); ++j) {
			(**i).collided(**j);
		}
	}
	
}

std::shared_ptr<Player> Scene::getPlayer() const {
	return player;
}