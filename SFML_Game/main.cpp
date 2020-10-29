#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Platform.h"
#include "Enemy_01.h"
void textureStage();

static const float VIEW_HEIGHT = 720.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
	int hitbox_E01 = 70;
	int hitbox_platforms = 35;
	int framplayer=0,dirplayer=1;
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Fuuma-Prototype", sf::Style::Close | sf::Style::Resize); // | sf::Style::Resize
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

	//------------------------------------------------------Texture------------------------------------------------------//
	sf::Texture playerTextures;
	if (!playerTextures.loadFromFile("Textures/PC Computer - The Messenger - Ninja02.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::RectangleShape playerT(sf::Vector2f(200.0f, 200.0f));
	playerT.setTexture(&playerTextures);

	sf::Texture testob;
	testob.loadFromFile("Stage/AutumnHills_8_BackAsset01.png");
	sf::RectangleShape test(sf::Vector2f(200.0f, 200.0f));
	test.setTexture(&testob);
	//test.setOrigin(sf::Vector2f(100.f, 100.f));
	test.setPosition(0, 0);

	sf::Texture stage01texture;
	stage01texture.loadFromFile("Stage/NinjaGaidenMapStage1-1BG.png");
	sf::RectangleShape stage01(sf::Vector2f(3900.0f, 720.0f));
	stage01.setTexture(&stage01texture);
	//test.setTextureRect(sf::IntRect(490, 440, 490, 440));
	



	
	//------------------------------------------------------Texture------------------------------------------------------//
	//sf::Vector2f spawnPoint = { 0.f, 0.f };

	Player player(&playerTextures, sf::Vector2u(4, 10), 0.1f, 250.0f, 200); // texture, imageCount, switchTime, speed, jumpHeight
	Enemy_01 enemy_01(&playerTextures, sf::Vector2u(4, 10), 0.1f, 250.0f, 200); // texture, imageCount, switchTime, speed, jumpHeight
	//------------------------------------------------------Platforms------------------------------------------------------//


	std::vector<Platform> platforms;
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(480.0f, 525.0f))); //texture,size,position
	platforms.push_back(Platform(nullptr, sf::Vector2f(10000.0f, 200.0f), sf::Vector2f(5680.0f, 500.0f))); 
	platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 400.0f), sf::Vector2f(880.0f, 100.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 400.0f), sf::Vector2f(480.0f, 0.0f)));

	//------------------------------------------------------Platforms------------------------------------------------------//


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
					//printf("%c", event.text.unicode);
				}
			}
		}

		player.Update(deltaTime);
		enemy_01.Update(deltaTime);

		sf::Vector2f direction;
		for (Platform& platform : platforms)
			if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f, hitbox_platforms))
				player.OnCollision(direction,deltaTime);

		for (Platform& platform2 : platforms)
			if (platform2.GetCollider().CheckCollision(enemy_01.GetCollider(), direction, 1.0f, hitbox_E01))
				enemy_01.OnCollision(direction, deltaTime);
			if (enemy_01.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f, hitbox_E01))
				player.OnCollision(direction, deltaTime);
		

		//platform1.GetCollider().CheckCollision(player.GetCollider(), 1.0f);
		//platform2.GetCollider().CheckCollision(player.GetCollider(), 1.0f);


		view.setCenter(player.GetPosition());
		window.clear(sf::Color::Red);
		window.setView(view);
		//window.draw(stage01);
		window.draw(test);
		player.Draw(window); /////////////////////// Draw ใครอยุ่ล่างสุด จะได้อยู่หน้าสุด
		enemy_01.Draw(window);

		for (Platform& platform : platforms)
		platform.Draw(window);
		//platform1.Draw(window);
		//platform2.Draw(window);
		window.display();
	}

	return 0;
}

void textureStage()
{

}