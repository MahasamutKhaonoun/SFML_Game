#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Platform.h"

static const float VIEW_HEIGHT = 720.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
	int framplayer=0,dirplayer=1;
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Fuuma-Prototype", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	sf::Texture playerTextures;
	//sf::Texture stage01texture;
	//sf::RectangleShape stage01(sf::Vector2f(3900.0f, 720.0f));
	//stage01texture.loadFromFile("Stage/NinjaGaidenMapStage1-1BG.png");
	//stage01.setTexture(&stage01texture);
	if (!playerTextures.loadFromFile("Textures/PC Computer - The Messenger - Ninja.png"))
	{
		std::cout << "Load failed" << std::endl;
	} 

	sf::Vector2f spawnPoint = { 0.f, 0.f };

	Player player(&playerTextures, sf::Vector2u(4, 10), 0.1f, 250.0f, 200); 

	std::vector<Platform> platforms;
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(480.0f, 525.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(880.0f, 500.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 400.0f), sf::Vector2f(880.0f, 100.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 400.0f), sf::Vector2f(480.0f, 0.0f)));

	//Platform platform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(480.0f, 525.0f));
	//Platform platform2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(880.0f, 500.0f));


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

		player.Update(deltaTime);

		sf::Vector2f direction;

		for (Platform& platform : platforms)
			if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
				player.OnCollision(direction,deltaTime);

		//platform1.GetCollider().CheckCollision(player.GetCollider(), 1.0f);
		//platform2.GetCollider().CheckCollision(player.GetCollider(), 1.0f);


		view.setCenter(player.GetPosition());
		window.clear(sf::Color::Red);
		window.setView(view);
		//window.draw(stage01);
		player.Draw(window);

		for (Platform& platform : platforms)
		platform.Draw(window);
		//platform1.Draw(window);
		//platform2.Draw(window);
		window.display();
	}

	return 0;
}