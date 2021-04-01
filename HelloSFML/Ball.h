#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Brick.h"
#include "Constants.h"
#include "Math.h"



class Ball
{

private:
	float ball_size;
	sf::CircleShape ball_shape;
	sf::FloatRect ball_boundingBox;
	float ball_posX;
	float ball_posY;
	int ball_damage;
	bool ChangeDirection;
	std::list<Brick*> CollisionBrickList;
	sf::Vector2f ball_direction;
	int NumberBall;

public:
	Ball(float size, int damage, int nbBall);
	~Ball();

	//Geters
	sf::Vector2f GetDirection();
	sf::CircleShape GetShape();
	sf::FloatRect GetBallBoundingBox();
	float GetBallXPosition();
	float GetBallYPosition();
	float GetBallSize();
	int GetBallDamage();
	bool GetChangeDirection();
	std::list<Brick*> GetCollisionBrickList();
	int GetNumberBall();

	void AddBrick(Brick* brick);
	void ResetCollisionBrickList();


	void InitializeBall();

	//Seters
	void SetBallPosition(float x, float y);
	void SetBallOrigin(float x, float y);
	void SetBallColor(sf::Color color);
	void SetChangeDirection(bool boool);
	void SetDirection(float x, float y);
	void XOppositeDirection();
	void YOppositeDirection();

	void InscreaseBallDamage(int newDamage);

};

