#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(235.0f, 235.0f)); //235
	body.setPosition(490.0f, 440.0f);// 360
	body.setTexture(texture);

}

Player::~Player()
{

}

void Player::Update(float deltaTime,int framplayer,int dirplayer)
{
	sf::Vector2f movement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		row = 3;
		movement.x -= speed * deltaTime;
		//framplayer =1;
		//dirplayer = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		row = 3;
		movement.x += speed * deltaTime;
		//framplayer = 1;
		//dirplayer = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		row = 4;
		movement.x += deltaTime;
		//framplayer = 2;
	}
	/*else
	{
		framplayer = 0;
	}
	switch (framplayer)
	{
	case 1:
		row = 3;
		break;
	case 0:
		row = 0;
		break;
	case 2:
		row = 8;
		break;
	default:
		break;
	}
	switch (dirplayer)
	{
	case 1:
		faceRight = true;
		break;
	case 0:
		faceRight = false;
		break;
	default:
		break;

	}*/


	if (movement.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);


}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}