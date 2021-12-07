#include "UI.h"

UI::UI() : window{ std::make_unique<sf::RenderWindow>(sf::VideoMode(850, 850), "Game") } {
	window->setFramerateLimit(60);
}

UI::~UI() {

}

void UI::reset() {
	window->clear();
}

void UI::draw(const sf::Drawable& drawable) const {
	window->draw(drawable);
}

void UI::display() {
	window->display();
}

void UI::pollEvent() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
	}
}

bool UI::isOpen() {
	return window->isOpen();
}

sf::Vector2i UI::getMouseLocation() {
	return sf::Mouse::getPosition(*window);
}