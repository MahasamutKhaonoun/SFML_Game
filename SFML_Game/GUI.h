#pragma once
#include <SFML\Graphics.hpp>
#include<iostream>
#include "Player.h"
class GUI
{
public:
	GUI(int takedamage);
	~GUI();
	sf::Vector2f PositionNow;
	void getPosition(sf::Vector2f);
	void Update(sf::Vector2f);
	void Draw(sf::RenderWindow& window);

private:
	int hp;
	int hpMax;

	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;
	sf::Texture UI_Frametexture;


};

