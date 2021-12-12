#include "UI.h"

UI::UI() : window{ std::make_unique<sf::RenderWindow>(sf::VideoMode(850, 850), "Game") } {
	window->setFramerateLimit(100);
}

UI::~UI() {

}

void UI::reset() {
	window->clear();
}

void UI::draw(const sf::Drawable& drawable) const {
	window->draw(drawable);
}

void UI::update() {
	if (objFocus) {
		seek = sf::Vector2f{ getMouseLocation() } - window->getView().getSize() / 2.0f;
		seek *= 0.1f;
		sf::View view = window->getView();
		view.setCenter(sf::Vector2f{ objFocus->getPosition().x, objFocus->getPosition().y } + seek);
		window->setView(view);
	}
}

void UI::display() {
	window->display();
}

void UI::pollEvent() {
	sf::Event event;
	while (window->pollEvent(event)) {
		switch (event.type) {
			case (sf::Event::Closed): {
				window->close();
			} break;

			case (sf::Event::Resized): {
				sf::FloatRect visibleArea(0, 0, static_cast<float>(event.size.width), static_cast<float>(event.size.height));
				window->setView(sf::View(visibleArea));
			} break;
		}
	}
}

bool UI::isOpen() const {
	return window->isOpen();
}

sf::Vector2i UI::getMouseLocation() const {
	return sf::Mouse::getPosition(*window);
}

sf::Vector2i UI::getAdjustedMouseLocation() const {
	return sf::Mouse::getPosition(*window) + static_cast<sf::Vector2i>(window->getView().getCenter()) - sf::Vector2i{ window->getView().getSize() / 2.0f };
}

void UI::setObjFocus(std::shared_ptr<Object> f) {
	objFocus = f;
}