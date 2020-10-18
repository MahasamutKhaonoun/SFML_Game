#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"
#include "Player.h"
void draw_stage();
int main()
{
	int framplayer=0,dirplayer=1;
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Fuuma-Prototype", sf::Style::Close | sf::Style::Resize);
	sf::Texture playerTextures;
	//sf::Texture stage01texture;
	//sf::RectangleShape stage01(sf::Vector2f(3900.0f, 720.0f));
	playerTextures.loadFromFile("Textures/PC Computer - The Messenger - Ninja.png");
	//stage01texture.loadFromFile("Stage/NinjaGaidenMapStage1-1BG.png");
	//stage01.setTexture(&stage01texture);

	/*if (!playerTextures.loadFromFile("Textures/PC Computer - The Messenger - Ninja.png"))
	{
		std::cout << "Load failed" << std::endl;
	} */


	Player player(&playerTextures, sf::Vector2u(4, 10), 0.1f, 250.0f);
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

		player.Update(deltaTime, framplayer, dirplayer);
		window.clear(sf::Color::Red);
		//window.draw(stage01);
		player.Draw(window);
		window.display();
	}

	return 0;
}