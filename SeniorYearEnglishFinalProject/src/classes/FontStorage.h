#pragma once
#include <SFML/Graphics.hpp>

struct FontStorage {
	inline static sf::Font font;
	inline static bool loadFont(std::string path) {
		return font.loadFromFile(path);
	}
};