#pragma once
#include <SFML/Graphics.hpp>

class Status : public sf::Drawable {
public:
	Status();
	~Status();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:

};