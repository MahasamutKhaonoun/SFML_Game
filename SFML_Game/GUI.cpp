#include "GUI.h"


GUI::GUI(int takedamage)
{
	this->hpMax = 200;
	this->hp = this->hpMax;
	UI_Frametexture.loadFromFile("Stage/Items and Icons.png");
	

}

GUI::~GUI()
{

}

void GUI::getPosition(sf::Vector2f x)
{
	this->PositionNow = x;
}

void GUI::Update(sf::Vector2f x)
{
	this->playerHpBar.setSize(sf::Vector2f(200.0f, 50.0f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setOrigin(500, 500);
	this->playerHpBar.setPosition(x);
	
	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
	this->playerHpBarBack.setOrigin(500, 500);
	this->playerHpBarBack.setPosition(x);

	sf::RectangleShape UIFrame(sf::Vector2f(300.0f, 200.0f));
	UIFrame.setTexture(&UI_Frametexture);
	UIFrame.setOrigin(-200, 530);
}

void GUI::Draw(sf::RenderWindow& window)
{
	window.draw(playerHpBarBack);
	window.draw(playerHpBar);
}
