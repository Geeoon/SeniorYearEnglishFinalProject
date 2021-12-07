#pragma once
#include <SFML/Graphics.hpp>

class UI {
public:
	UI();
	~UI();
	void reset();
	void draw(const sf::Drawable& drawable) const;
	void display();
	void pollEvent();
	bool isOpen();
	sf::Vector2i getMouseLocation();

private:
	std::unique_ptr<sf::RenderWindow> window{ nullptr };
};