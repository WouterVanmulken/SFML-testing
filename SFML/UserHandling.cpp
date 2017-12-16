#include "stdafx.h"
#include "UserHandling.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>


UserHandling::UserHandling()
{
}


UserHandling::~UserHandling()
{
}

void UserHandling::handleKeyboard(sf::RectangleShape& player)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		player.move(0, -.1f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		player.move(0, .1f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		player.move(-0.1f, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		player.move(.1f, 0);
	}
}

void UserHandling::handleMouse(sf::Window& window, sf::RectangleShape& player)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousepos = sf::Mouse::getPosition(window);
		player.setPosition(static_cast<float>(mousepos.x), static_cast<float>(mousepos.y));
	}
}
