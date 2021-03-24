#include <SFML/Graphics.hpp>

#pragma once
class Brick
{
private:
	float brickSizeX;
	float brickSizeY;
	float brickPosX;
	float brickPosY;
	int brickLife;
	sf::RectangleShape brickShape;

public :
	Brick(float sizeX, float sizeY, int lifePoints);
	float GetSizeX();
	float GetSizeY();
	sf::RectangleShape GetBrickShape();

	void SetBrickColor(sf::Color color);

};