#include <SFML/Graphics.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

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
	Brick(float sizeX, float sizeY);
	~Brick();
	float GetSizeX();
	float GetSizeY();
	sf::RectangleShape GetBrickShape();
	sf::FloatRect GetBrickBoundingBox();
	int GetBrickLife();

	void SetBrickPosition(float x, float y);
	void SetBrickColor();

	void RemoveLife(int points);

	void SetRandomBrickLife();

};