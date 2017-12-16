#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>


sf::RectangleShape player(sf::Vector2f(100, 100));

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

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 400), "SFML works!");
//	sf::CircleShape shape(100.f);

	player.setFillColor(sf::Color::Cyan);
//	shape.setFillColor(sf::Color::Green);

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


		window.clear();
//		window.draw(shape);
		window.draw(player);
		window.display();
	}

	return 0;
}

