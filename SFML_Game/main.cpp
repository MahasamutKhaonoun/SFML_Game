#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Platform.h"
#include "Enemy_01.h"
#include "GUI.h"
#include <string.h>
#include <sstream>

static const float VIEW_HEIGHT = 1080.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
	float HPUpdate = 200.0f;
	int hitbox_E01 = 50;
	int hitbox_platforms = 35;
	float damage = 0.0f;
	bool inslash = false;
	bool enemy_alive = true;
	bool indamage = false;
	int Nscore = 0;
	bool checkscore = false;
	sf::RenderWindow window(sf::VideoMode(1360, 720), "Fuuma-Prototype"); // | sf::Style::Resize
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));


	
	//------------------------------------------------------Texts------------------------------------------------------//
	
	//------------------------------------------------------Texts------------------------------------------------------//
	
	
	//------------------------------------------------------Texture------------------------------------------------------//
	sf::Texture playerTextures;
	if (!playerTextures.loadFromFile("Textures/PC Computer - The Messenger - Ninja02.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::RectangleShape playerT(sf::Vector2f(200.0f, 200.0f));
	playerT.setTexture(&playerTextures);
	sf::RectangleShape testP(sf::Vector2f(60.0f, 120.0f));
	testP.setFillColor(sf::Color::Transparent);
	testP.setOutlineThickness(3.f);
	testP.setOutlineColor(sf::Color::Green);
	testP.setOrigin(60.0f / 2.0f, 120.0f / 2.0f);

	sf::Texture Green_KappaTextures;
	if (!Green_KappaTextures.loadFromFile("Textures/Enemies_Green Kappa.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::RectangleShape Green_KappaT(sf::Vector2f(250.0f, 200.0f));
	Green_KappaT.setTexture(&Green_KappaTextures);
	sf::RectangleShape testE(sf::Vector2f(85.0f, 120.0f));
	testE.setFillColor(sf::Color::Transparent);
	testE.setOutlineThickness(3.f);
	testE.setOutlineColor(sf::Color::Red);
	testE.setOrigin(85.0f / 2.0f, 120.0f / 2.0f);

	sf::Texture stage01texture;
	stage01texture.loadFromFile("Stage/AutumnHills_Parallax05_01_16.png");
	sf::RectangleShape stage01(sf::Vector2f(1360.0f, 1080.0f));
	stage01.setTexture(&stage01texture);
	stage01.setOrigin(1360.0f / 2.0f, 1080.0f / 2.0f);
	//test.setTextureRect(sf::IntRect(490, 440, 490, 440));

	sf::Texture stage01textureF;
	stage01textureF.loadFromFile("Stage/AutumnHills_RoomBackground01B_8.png");
	sf::RectangleShape stage01F(sf::Vector2f(1360.0f, 1080.0f));
	stage01F.setTexture(&stage01textureF);
	stage01F.setOrigin(1360.0f / 2.0f, 1080.0f / 2.0f);

	sf::Texture UI_Frametexture;
	UI_Frametexture.loadFromFile("Stage/Items and Icons.png");
	sf::RectangleShape UIFrame(sf::Vector2f(300.0f, 200.0f));
	UIFrame.setTexture(&UI_Frametexture);
	UIFrame.setOrigin(-200 , 530);
	//UIFrame.setRotation(180.f);

	sf::Texture groundwood;
	groundwood.loadFromFile("Stage/AutumnHillsTileset_9.png");
	sf::RectangleShape R_groundwood(sf::Vector2f(200.0f, 200.0f));
	R_groundwood.setTexture(&groundwood);

	sf::Texture groundgrass;
	groundgrass.loadFromFile("Stage/AutumnHillsTileset_10.png"); 
	sf::RectangleShape R_groundgrass(sf::Vector2f(100.0f, 100.0f));
	R_groundgrass.setTexture(&groundgrass);
	//test.setOrigin(sf::Vector2f(100.f, 100.f));

	sf::Texture wood;
	wood.loadFromFile("Stage/AutumnHillsTileset_12.png");
	sf::RectangleShape R_wood(sf::Vector2f(100.0f, 100.0f));
	R_wood.setTexture(&wood);
	//test.setOrigin(sf::Vector2f(100.f, 100.f));

	//------------------------------------------------------Texture------------------------------------------------------//
	//sf::Vector2f spawnPoint = { 0.f, 0.f };
	
	Player player(&playerTextures, sf::Vector2u(4, 10), 0.1f, 300.0f, 200); // texture, imageCount, switchTime, speed, jumpHeight
	Enemy_01 enemy_01(&Green_KappaTextures, sf::Vector2u(4,1), 0.3f, 250.0f, sf::Vector2f(400.0f, 440.0f)); // texture, imageCount, switchTime, speed, 
	GUI gui(damage);

	//------------------------------------------------------Platforms------------------------------------------------------//

	//Test System Room
	std::vector<Platform> platforms;
	std::vector<Platform> props;
		platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 300.0f), sf::Vector2f(480.0f, 600.0f))); //texture,size,position
		platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(880.0f, 500.0f)));
		platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 400.0f), sf::Vector2f(880.0f, 100.0f)));
		platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 400.0f), sf::Vector2f(480.0f, 0.0f)));
		platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(1580.0f, 500.0f)));

	//Stage 1.1
		//platforms.push_back(Platform(&groundgrass, sf::Vector2f(400.0f, 1000.0f), sf::Vector2f(480.0f, 2000.0f))); //p1
		//platforms.push_back(Platform(&groundgrass, sf::Vector2f(600.0f, 1000.0f), sf::Vector2f(980.0f, 2200.0f))); //p2
		//platforms.push_back(Platform(nullptr, sf::Vector2f(2000.0f, 1000.0f), sf::Vector2f(2280.0f, 2300.0f))); //p3
		//platforms.push_back(Platform(&wood, sf::Vector2f(200.0f, 500.0f), sf::Vector2f(1950.0f, 1550.0f))); //p4
		//platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 500.0f), sf::Vector2f(1580.0f, 1250.0f))); //p5
		//platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 100.0f), sf::Vector2f(2200.0f, 1200.0f))); //Item
		//platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 100.0f), sf::Vector2f(2500.0f, 1200.0f))); //Item
		//platforms.push_back(Platform(&wood, sf::Vector2f(200.0f, 500.0f), sf::Vector2f(2800.0f, 1550.0f))); //p6
		//platforms.push_back(Platform(nullptr, sf::Vector2f(2500.0f, 1000.0f), sf::Vector2f(4800.0f, 2300.0f))); //p13
		//platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 100.0f), sf::Vector2f(4000.0f, 1500.0f))); //Item
		//platforms.push_back(Platform(&groundwood, sf::Vector2f(200.0f, 500.0f), sf::Vector2f(4200.0f, 1550.0f))); //p7
		//platforms.push_back(Platform(&groundwood, sf::Vector2f(200.0f, 700.0f), sf::Vector2f(4400.0f, 1450.0f))); //p8
		//platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 100.0f), sf::Vector2f(4800.0f, 1000.0f))); //p9
		//platforms.push_back(Platform(nullptr, sf::Vector2f(50.0f, 100.0f), sf::Vector2f(5100.0f, 800.0f))); //Item
		//platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 100.0f), sf::Vector2f(5400.0f, 1000.0f))); //p10
		//platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 600.0f), sf::Vector2f(5800.0f, 1550.0f))); //p11
		//platforms.push_back(Platform(nullptr, sf::Vector2f(1500.0f, 1000.0f), sf::Vector2f(6800.0f, 1750.0f))); //p12

		//props.push_back(Platform(nullptr, sf::Vector2f(50.0f, 100.0f), sf::Vector2f(1000.0f, 1200.0f)));
	




	//------------------------------------------------------Platforms------------------------------------------------------//


	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 30.0f)
			deltaTime = 1.0f / 30.0f;

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J))
		{
			inslash = true;
			testP.setSize(sf::Vector2f(120.f, 120.f));
			testP.setOrigin(120.0f / 2.0f, 120.0f / 2.0f);
			if (testE.getGlobalBounds().intersects(testP.getGlobalBounds())) {
				printf("Dead!!");
				enemy_alive = false;
				checkscore = true;
				testE.scale(0, 0);
			}
		}
		else
		{
			testP.setSize(sf::Vector2f(60.0f, 120.0f));
			testP.setOrigin(60.0f / 2.0f, 120.0f / 2.0f);
			inslash = false;
		}
		if (checkscore == true)
		{
			Nscore += 20;
			checkscore = false;
		}
		player.Update(deltaTime);
		enemy_01.Update(deltaTime);
		
		sf::Vector2f direction;
		for (Platform& platform : platforms)
			if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 2.0f, hitbox_platforms))
			{
				player.OnCollision(direction, deltaTime);
			}
				
		
	
		if (enemy_alive)
		{
			for (Platform& platform2 : platforms)
				if (platform2.GetCollider().CheckCollision(enemy_01.GetCollider(), direction, 1.0f, hitbox_E01))
					enemy_01.OnCollision(direction, deltaTime);
			/*if (enemy_01.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f, hitbox_E01))
			{
				enemy_01.OnCollision(direction, deltaTime);
				enemy_alive = true;
				if (inslash == true)
				{
					enemy_alive = false;
				}
			}*/
		}
		if (inslash == false)
		{
			if (testP.getGlobalBounds().intersects(testE.getGlobalBounds())) {
				printf("Collision!! Player Take Damage");
				indamage = true;
			}else indamage = false;
		}
		if (indamage == true)
		{
			HPUpdate -= 20.0f;
			indamage = false;
		}
		if(HPUpdate<0)
		{
			HPUpdate = 20;
		}

		sf::Font score;
		if (!score.loadFromFile("Fonts/NikkyouSans-B6aV.ttf"))
		{
			printf("Can not load font score");
		}
		std::stringstream ss;
		ss << "Score = " << Nscore;
		sf::Text Tscore;
		Tscore.setFont(score);
		Tscore.setCharacterSize(24);
		Tscore.setFillColor(sf::Color::Red);
		Tscore.setString(ss.str());
		//Tscore.setStyle(sf::Text::Bold);
		Tscore.setOrigin(-200, 330);

		testP.setPosition(player.GetPosition());
		testE.setPosition(enemy_01.GetPosition());
		stage01.setPosition(player.GetPosition());
		stage01F.setPosition(player.GetPosition());
		UIFrame.setPosition(player.GetPosition());
		Tscore.setPosition(player.GetPosition());
		view.setCenter(player.GetPosition());
		window.clear(sf::Color::Red);
		window.setView(view);
		window.draw(stage01);
		window.draw(stage01F);
		window.draw(testE);
		window.draw(testP);
		//window.draw(R_groundwood);
		if (enemy_alive)
		{
			enemy_01.Draw(window);
		}
		
		player.Draw(window); /////////////////////// Draw ใครอยุ่ล่างสุด จะได้อยู่หน้าสุด
		for (Platform& platform : platforms)
		platform.Draw(window);



		//platform1.Draw(window);
		//platform2.Draw(window);
		window.draw(UIFrame);
		window.draw(Tscore);
		gui.Update(player.GetPosition());
		gui.Draw(window);
		window.display();
	}

	return 0;
}
