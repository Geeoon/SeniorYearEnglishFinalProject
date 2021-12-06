#include "Scene.h"

Scene::Scene() {
	entities.push_back(std::make_unique<Player>(0.0f, 0.0f));
}

Scene::~Scene() {

}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& entity : entities) {
		target.draw(*entity);
	}
}

void Scene::update() {
	elapsedTime = clock.getElapsedTime();
	clock.restart();
	for (auto& entity : entities) {
		entity->update();
	}
}