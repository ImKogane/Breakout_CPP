#include <SFML/Graphics.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cstdlib>

#pragma once
class Brick
{
private:
	float brickSizeX;
	float brickSizeY;
	float brickPosX;
	float brickPosY;
	int brickLife;
	int brickScore;
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
	int GetBrickScore();

	void SetBrickPosition(float x, float y);
	void SetBrickColor();

	void RemoveLife(int points);

	void SetRandomBrickLife();

};