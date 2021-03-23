#include "Ball.h"


Ball::Ball(float size)
{
	ballSize = size;

	InitializeBall();
}

/// <summary>
/// Initialize ball value
/// </summary>
void Ball::InitializeBall()
{
	ballShape.setRadius(ballSize);
	ballShape.setPosition(ballPosX, ballPosY);
	ballBoundingBox = ballShape.getGlobalBounds();
	SetBallColor(sf::Color::Green);
}

/// <summary>
/// Get the shape
/// </summary>
/// <returns></returns>
sf::CircleShape Ball::GetShape()
{
	return ballShape;
}

/// <summary>
/// Get the bounding box (collision box) of the ball shape
/// </summary>
/// <returns> Ball bounding box </returns>
sf::FloatRect Ball::GetBallBoundingBox()
{
	return ballBoundingBox;
}


float Ball::GetBallXPosition()
{
	return ballPosX;
}
float Ball::GetBallYPosition()
{
	return ballPosY;
}
float Ball::GetBallSize()
{
	return ballSize;
}

/// <summary>
/// Set ball color
/// </summary>
/// <param name="color"> Color to set the ball color </param>
void Ball::SetBallColor(sf::Color color)
{
	ballShape.setFillColor(color);
}

/// <summary>
/// Set the ball shape origin
/// </summary>
/// <param name="x"> Origin point on X axis </param>
/// <param name="y"> Origin point on Y axis </param>
void Ball::SetBallOrigin(float x, float y)
{
	ballShape.setOrigin(x, y);
}

/// <summary>
/// Set the ball position
/// </summary>
/// <param name="x"> Ball position on X axis </param>
/// <param name="y"> Ball position on Y axis </param>
void Ball::SetBallPosition(float x, float y)
{
	ballPosX = x;
	ballPosY = y;
	ballShape.setPosition(ballPosX, ballPosY);
}