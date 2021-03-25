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
	sf::FloatRect brickBoundingBox;

public :
	Brick(float sizeX, float sizeY, int lifePoints);
	float GetSizeX();
	float GetSizeY();
	sf::RectangleShape GetBrickShape();
	sf::FloatRect GetBrickBoundingBox();

	void SetBrickPosition(float x, float y);
	void SetBrickColor(sf::Color color);
	void SetBrickShape();

};