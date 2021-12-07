#include "Scene.h"

Scene::Scene() {
	player = std::make_shared<Player>(0.0f, 0.0f);
	entities.push_back(player);
}

Scene::~Scene() {

}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (auto& entity : entities) {
		target.draw(*entity);
	}
}

void Scene::update(sf::Vector2i mouseLocation) {
	elapsedTime = clock.getElapsedTime();
	clock.restart();

	player->setOrientation(atan2f(mouseLocation.y - player->getPosition().y, mouseLocation.x - player->getPosition().x) * 180.0f / 3.141592f);

	for (auto& entity : entities) {
		entity->update(elapsedTime.asSeconds());
	}
}