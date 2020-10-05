#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	animation(texture,imageCount, switchTime)
{
	this->speed = speed;
	row = 8;
	faceRight = true;

	body.setSize(sf::Vector2f(235.0f, 235.0f));
	body.setPosition(490.0f, 360.0f);
	body.setTexture(texture);
}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		movement.x -= speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
			movement.x += speed * deltaTime;
	}
	if (movement.x == 0.0f)
	{
		row = 8;
	}
	else
	{
		row = 8;
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
