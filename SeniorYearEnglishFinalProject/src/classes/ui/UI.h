#pragma once
#include <SFML/Graphics.hpp>
#include "../scene/Object.h"

class UI {
public:
	UI();
	~UI();
	void reset();
	void draw(const sf::Drawable& drawable) const;
	void update();
	void display();
	void pollEvent();
	bool isOpen() const;
	sf::Vector2i getMouseLocation() const;
	sf::Vector2i getAdjustedMouseLocation() const;
	void setObjFocus(std::shared_ptr<Object> f);

private:
	std::unique_ptr<sf::RenderWindow> window{ nullptr };
	std::shared_ptr<Object> objFocus{ nullptr };
	sf::Vector2f seek;
};