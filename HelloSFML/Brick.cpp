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

void Brick::SetBrickColor(sf::Color color)
{
	brickShape.setFillColor(color);
}