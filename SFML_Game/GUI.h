#pragma once
#include <SFML\Graphics.hpp>
#include<iostream>
#include <string.h>
#include <sstream>
#include "Player.h"

class GUI
{
public:
	GUI(int takedamage);
	~GUI();
	sf::Vector2f PositionNow;
	void getPosition(sf::Vector2f);
	void Update(sf::Vector2f);
	void updateScore(bool,int);
	void updateHP(bool, int);
	void Draw(sf::RenderWindow& window);

private:
	int hp;
	int hpMax;
	int Nscore;

	int hp_amount;
	int score_amount;

	bool checkHP;
	bool checkscore;

	std::stringstream ss;

	sf::Font score;
	sf::Text Tscore;

	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;
	sf::Texture UI_Frametexture;


};

