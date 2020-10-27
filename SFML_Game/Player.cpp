#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
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
	body.setPosition(490.0f, 440.0f);// 360
	body.setTexture(texture);

}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
	velocity.x *= 0.0f;
	velocity_jump.x *= 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		row = 3;
		velocity.x -= speed;
		if (inclimb == true)
		{
			row = 4;
			velocity.x += deltaTime;
			inclimb = false;
		}

		this->inAction = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		row = 3;
		velocity.x += speed;
		if (inclimb == true)
		{
			row = 4;
			velocity.x += deltaTime;
			inclimb = false;
		}
		this->inAction = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && this->inAction == false)
	{
		row = 8;
		velocity.x = deltaTime;
		this->inAction = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		row = 2;
		velocity.x =  deltaTime;
		//movement.x += deltaTime;
		//framplayer = 2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K) && canJump == true && inclimb == false) 
	{
		canJump = false;
		velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);
		//square root (2.0f * gravity * jumpHeight);

	}

	velocity.y += 981.0f * deltaTime;

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

	if (canJump == false)
	{
		row = 2;
		velocity_jump.x = deltaTime;
		this->inAction = false;
	}


	if (animation.Update(row, deltaTime, faceRight))
	{
		this->inAction = false;
	}
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);


}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction,float deltaTime)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left
		velocity.x = 0.0f;
		this->canJump = true;
		this->inclimb = true;
	
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right
		velocity.x = 0.0f;
		this->canJump = true;
		this->inclimb = true;
	}
	if (direction.y < 0.0f)
	{
		//Collision on the bottom
		velocity.x = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top
		velocity.x = 0.0f;
	}

	if (inclimb == true)
	{
		velocity.y = 0;
	}
}
