#include "Scene.h"

Scene::Scene() {
	player = std::make_shared<Player>(100.0f, 100.0f, objectsQueue);
	objects.push_back(player);
	objects.push_back(std::make_shared<Dummy>(200.0f, 200.0f, objectsQueue));
}

Scene::~Scene() {

}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
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
	//std::for_each(entities.begin(), entities.end(), [&](std::shared_ptr<Object> e) { e-> });
}

std::shared_ptr<Player> Scene::getPlayer() const {
	return player;
}