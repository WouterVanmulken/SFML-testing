#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>


sf::RectangleShape player(sf::Vector2f(100, 100));
sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

void handleKeys()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		player.move(0,-.1f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		player.move(0,.1f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		player.move(-0.1f,0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		player.move( .1f,0);
	}
}
void handleMouse()
{
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousepos = sf::Mouse::getPosition(window);
		player.setPosition(static_cast<float>(mousepos.x),static_cast<float>(mousepos.y));
	}
}

int main()
{
	player.setFillColor(sf::Color::Cyan);
	player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if(event.type == sf::Event::Resized)
			{
				std::cout << "width : "<<event.size.width << " height "<<event.size.height << std::endl;
			}
			if(event.type == sf::Event::TextEntered)
			{
				printf("%c", event.text.unicode);
			}
		}
		handleKeys();
		handleMouse();

		window.clear();\
		window.draw(player);
		window.display();
	}

	return 0;
}

