#include <list>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Brick.h"


#pragma once
class Ball
{

private: 
	float ballSize;
	sf::CircleShape ballShape;
	sf::FloatRect ballBoundingBox;
	float ballPosX;
	float ballPosY;
	bool ChangeDirection;
	std::list<Brick*> CollisionBrickList;

public :
	Ball(float size);

	//Geters
	sf::CircleShape GetShape();
	sf::FloatRect GetBallBoundingBox();
	float GetBallXPosition();
	float GetBallYPosition();
	float GetBallSize();
	bool GetChangeDirection();
	std::list<Brick*> GetCollisionBrickList();

	void AddBrick(Brick* brick);
	void ResetCollisionBrickList();


	void InitializeBall();

	//Seters
	void SetBallPosition(float x, float y);
	void SetBallOrigin(float x, float y);
	void SetBallColor(sf::Color color);
	void SetChangeDirection(bool boool);

};

