#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "UserHandling.h"


sf::RectangleShape player(sf::Vector2f(100, 100));
sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");



int main()
{
	player.setFillColor(sf::Color::Cyan);
	player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);
	
	sf::Texture texture;
	texture.loadFromFile("./img/bob.jpg");
	player.setTexture(&texture);

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
		UserHandling::handleKeyboard(player);
		UserHandling::handleMouse(window, player);

		window.clear();
		window.draw(player);
		
		window.display();
	}

	return 0;
}

