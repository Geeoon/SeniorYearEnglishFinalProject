#pragma once
#include <SFML/Graphics.hpp>

class Element : sf::Drawable {
public:
	Element(sf::Vector2f p);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:
	sf::Vector2f position;
};