#include "Scene.h"

Scene::Scene() {
	player = std::make_shared<Player>(100.0f, 100.0f, entitiesQueue);
	entities.push_back(player);
	entities.push_back(std::make_shared<Dummy>(200.0f, 200.0f, entitiesQueue));
}

Scene::~Scene() {

}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	std::for_each(entities.begin(), entities.end(), [&](std::shared_ptr<Entity> e) { target.draw(*e); });
}

void Scene::update(sf::Vector2i mouseLocation) {
	elapsedTime = clock.getElapsedTime();
	clock.restart();

	player->setOrientation(atan2f(mouseLocation.y - player->getPosition().y, mouseLocation.x - player->getPosition().x) * 180.0f / 3.141593f);

	//entities.push_back(std::make_shared<Bullet>(Vector2{ 0.0f, 0.0f }, 0.0f));
	std::for_each(entities.begin(), entities.end(), [&](std::shared_ptr<Entity> e) { e->update(elapsedTime.asSeconds()); });
	while (entitiesQueue.size() > 0) {
		entities.push_back(entitiesQueue.front());
		entitiesQueue.front()->update(elapsedTime.asSeconds());
		entitiesQueue.pop();
	}
}

std::shared_ptr<Player> Scene::getPlayer() const {
	return player;
}