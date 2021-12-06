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

private:
	std::unique_ptr<sf::RenderWindow> window{ nullptr };
};