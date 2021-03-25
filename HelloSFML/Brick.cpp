#include "Brick.h"

/// <summary>
/// Constructor of the Brick object class
/// </summary>
/// <param name="posX"> X axis position in level</param>
/// <param name="posY"> Y axis position in level </param>
/// <param name="sizeX"> Y axis size </param>
/// <param name="sizeY"> Y axis size </param>
/// <param name="lifePoints"> Brick life points </param>
Brick::Brick(float sizeX, float sizeY, int lifePoints)
{
	brickSizeX = sizeX;
	brickSizeY = sizeY;
	brickLife = lifePoints;

	brickShape = sf::RectangleShape(sf::Vector2f(brickSizeX, brickSizeY));
}

/// <summary>
/// Get the brick size in X axis
/// </summary>
/// <returns>Brick X size </returns>
float Brick::GetSizeX()
{
	return brickSizeX;
}

/// <summary>
/// Get the brick size in Y axis
/// </summary>
/// <returns>Brick Y size </returns>
float Brick::GetSizeY()
{
	return brickSizeY;
}

/// <summary>shapesize in Y axis
/// </summary>
/// <returns>Brick shape </returns>
sf::RectangleShape Brick::GetBrickShape()
{
	return brickShape;
}

/// <summary>
/// Get the bounding box (collision box) of the brick shape
/// </summary>
/// <returns> Brick bounding box </returns>
sf::FloatRect Brick::GetBrickBoundingBox()
{
	return brickBoundingBox;
}

void Brick::SetBrickColor(sf::Color color)
{
	brickShape.setFillColor(color);
}


/// <summary>
/// Set the brick position
/// </summary>
/// <param name="x"> Brick position on X axis </param>
/// <param name="y"> Brick position on Y axis </param>
void Brick::SetBrickPosition(float x, float y)
{
	brickPosX = x;
	brickPosY = y;
	brickShape.setPosition(brickPosX, brickPosY);
}

void Brick::SetBrickShape()
{
	//brickShape = new sf::RectangleShape(sf::Vector2f(brickSizeX, brickSizeY));
}