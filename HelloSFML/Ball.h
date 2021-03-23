#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once
class Ball
{

private: 
	float ballSize;
	sf::CircleShape ballShape;
	sf::FloatRect ballBoundingBox;
	float ballPosX;
	float ballPosY;

public :
	Ball(float size);

	//Geters
	sf::CircleShape GetShape();
	sf::FloatRect GetBallBoundingBox();
	float GetBallXPosition();
	float GetBallYPosition();
	float GetBallSize();

	void InitializeBall();

	//Seters
	void SetBallPosition(float x, float y);
	void SetBallOrigin(float x, float y);
	void SetBallColor(sf::Color color);
};

