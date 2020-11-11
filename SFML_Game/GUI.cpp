#include "GUI.h"


GUI::GUI(int takedamage)
{
	this->hpMax = 200;
	this->hp = this->hpMax;
	this->Nscore = 0;
	this->checkHP = false;
	this->checkscore = false;
	this->Tscore = Tscore;
	UI_Frametexture.loadFromFile("Stage/Items and Icons.png");

	if (!score.loadFromFile("Fonts/NikkyouSans-B6aV.ttf"))
	{
		printf("Can not load font score");
	}

	

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

	this->Tscore.setFont(score);
	this->Tscore.setCharacterSize(24);
	this->Tscore.setFillColor(sf::Color::Red);
	//this->Tscore.setStyle(sf::Text::Bold);
	this->Tscore.setOrigin(-200, 330);
	this->Tscore.setPosition(x);
	this->Tscore.setString(ss.str());

}

void GUI::updateScore(bool takescore,int score_amount)
{
	this->checkscore = takescore;
	this->score_amount = score_amount;
	if (checkscore == true)
	{
		Nscore += score_amount;
		checkscore = false;
	}
	ss << "Score = " << Nscore;
}

void GUI::updateHP(bool takedamage, int dmg_amount)
{
	this->checkHP = takedamage;
	this->hp_amount = dmg_amount;
	if (checkHP== true)
	{
		hp -= 20.0f;
		checkHP = false;
	}
	if (hp < 0)
	{
		hp = 0;
	}
}


void GUI::Draw(sf::RenderWindow& window)
{
	window.draw(playerHpBarBack);
	window.draw(playerHpBar);
	window.draw(Tscore);
}


