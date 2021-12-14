#pragma once
#include <iostream>
#include "../FontStorage.h"
#include "Entity.h"

class Text : public Entity {
public:
	Text(float x, float y, std::shared_ptr<Level> l, size_t csize, std::string t);
	Text(Vector2 pos, std::shared_ptr<Level> l, size_t csize, std::string t);
	~Text() = default;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void update(float elapsedTime) override;
	void setText(std::string t);

protected:
	sf::Text text;
};