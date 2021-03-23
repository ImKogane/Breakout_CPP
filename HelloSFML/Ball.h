#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once
class Ball
{

private: 
	float ballSize;
	sf::CircleShape ballShape;
	float ballPosX;
	float ballPosY;

public :
	Ball(float size, float x, float y);


	sf::CircleShape GetShape();


	void InitializeBall();

	void SetBallPosition(float x, float y);
	void SetBallOrigin(float x, float y);
	void SetBallColor(sf::Color color);
};

