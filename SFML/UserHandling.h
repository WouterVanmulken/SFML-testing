#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Window.hpp>

class UserHandling
{
public:
	UserHandling();
	~UserHandling();

	static void handleKeyboard(sf::RectangleShape& player);
	static void handleMouse(sf::Window& window, sf::RectangleShape& player);
};

