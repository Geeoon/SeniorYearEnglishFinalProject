#include "Text.h"

Text::Text(float x, float y, std::shared_ptr<Level> l, size_t csize, std::string t) : Entity{ x, y, l } {
	text.setFont(FontStorage::font);
	text.setString(t);
	text.setCharacterSize(csize);
	text.setFillColor(sf::Color::Green);
	text.setPosition(x, y);
}

Text::Text(Vector2 pos, std::shared_ptr<Level> l, size_t csize, std::string t) : Entity{ pos, l } {
	text.setFont(FontStorage::font);
	text.setString(t);
	text.setCharacterSize(csize);
	text.setFillColor(sf::Color::Green);
	text.setPosition(pos.x, pos.y);
}

void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(text);
}

void Text::update(float elapsedTime) {
	text.setOrigin(text.getLocalBounds().width / 2.0f, text.getLocalBounds().height / 2.0f);
	text.setPosition(position.x, position.y);
}

void Text::setText(std::string t) {
	text.setString(t);
}