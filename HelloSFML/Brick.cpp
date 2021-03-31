#include "Brick.h"
#include "Level.h"

/// <summary>
/// Constructor of the Brick object class
/// </summary>
/// <param name="posX"> X axis position in level</param>
/// <param name="posY"> Y axis position in level </param>
/// <param name="sizeX"> Y axis size </param>
/// <param name="sizeY"> Y axis size </param>
/// <param name="lifePoints"> Brick life points </param>
Brick::Brick(float sizeX, float sizeY)
{
	brickSizeX = sizeX;
	brickSizeY = sizeY;

	SetRandomBrickLife();
	SetBrickColor();

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
	return brickShape.getGlobalBounds();
}

/// <summary>
/// Get the bounding box (collision box) of the brick shape
/// </summary>
/// <returns> Brick bounding box </returns>
int Brick::GetBrickLife()
{
	return 	brickLife;
}

void Brick::SetBrickColor()
{
	switch (brickLife)
	{
	case 1:
		brickShape.setFillColor(sf::Color::White);
		break;
	case 2:
		brickShape.setFillColor(sf::Color(173, 231, 255));
		break;
	case 3:
		brickShape.setFillColor(sf::Color(116, 215, 255));
		break;
	case 4:
		brickShape.setFillColor(sf::Color(0, 182, 255));
		break;
	case 5:
		brickShape.setFillColor(sf::Color(0, 107, 151));
		break;
	default:
		brickShape.setFillColor(sf::Color::White);
		break;
	}
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

void Brick::RemoveLife(int points)
{
	brickLife -= points;
	SetBrickColor();
}

/// <summary>
/// Brick object destructor
/// </summary>
Brick::~Brick()
{
	std::cout << "Brick destroyed.";
}

void Brick::SetRandomBrickLife()
{
	
	brickLife = (rand() % 5) + 1;
}