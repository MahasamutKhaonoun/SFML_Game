#include "Enemy_01.h"

Enemy_01::Enemy_01(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	this->inAction = false;
	this->canJump = false;
	this->inclimb = false;
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(140.0f, 170.0f)); //235
	//body.setScale(1.f, 1.6f);
	body.setOrigin({ body.getSize().x / 2.0f,body.getSize().y / 2.0f });
	body.setPosition(550.0f, 450.0f);// 360
	body.setTexture(texture);
}
Enemy_01::~Enemy_01()
{

}


void Enemy_01::Update(float deltaTime)
{
	velocity.x *= 0.0f;
	velocity_jump.x *= 0.0f;
	velocity_attack *= 0.0f;
	//velocity.x -= speed;
	//velocity.x += speed;
	row = 0;
	velocity.x += deltaTime;
	velocity.y = sqrt(2.0f * 981.0f * jumpHeight);
	if (velocity.x == 0.0f && this->inAction == false)
	{
		row = 0;
	}
	else if (velocity.x != 0.0f && this->inAction == false)
	{
		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	if (animation.Update(row, deltaTime, faceRight))
	{
		this->inAction = false;
	}
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);


}

void Enemy_01::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Enemy_01::OnCollision(sf::Vector2f direction, float deltaTime)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//Collision on the bottom
		velocity.x = 0.0f;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top
		velocity.x = 0.0f;
	}
}
