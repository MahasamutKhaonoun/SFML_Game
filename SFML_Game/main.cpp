#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"
#include "Player.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Fuuma-Prototype", sf::Style::Close | sf::Style::Resize);
	sf::Texture playerTextures;
	playerTextures.loadFromFile("Textures/PC Computer - The Messenger - Ninja.png");
	/*if (!playerTextures.loadFromFile("Textures/PC Computer - The Messenger - Ninja.png"))
	{
		std::cout << "Load failed" << std::endl;
	} */


	Player player(&playerTextures, sf::Vector2u(4, 10), 0.2f, 100.0f);
	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				printf("New window width: %i New window height: %i\n", event.size.width, event.size.height);
				break;
			case sf::Event::TextEntered:
				if (event.text.unicode < 128)
				{
					printf("%c", event.text.unicode);
				}
			}
		}
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.move(-0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			//player.move(0.0f, -0.1f);
			player.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			//player.move(0.0f, 0.1f);
			player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 0, textureSize.x, textureSize.y));
		}*/
		//animation.Update(0, deltaTime, false);
		//player.setTextureRect(animation.uvRect);

		player.Update(deltaTime);
		window.clear(sf::Color::Red);
		player.Draw(window);
		window.display();
	}

	return 0;
}