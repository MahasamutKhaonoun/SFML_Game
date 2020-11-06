#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Enemy_01
{
public:
	Enemy_01(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f pos);
	~Enemy_01();
	void CheckAlive(bool);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction, float deltaTime);


	Collider GetCollider() { return Collider(body); }
	sf::Vector2f GetPosition() { return body.getPosition(); }

private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;

	sf::Vector2f velocity;
	sf::Vector2f velocity_jump;
	sf::Vector2f velocity_attack;
	bool canJump;

	bool inAction;//action check
	bool inclimb;
};

