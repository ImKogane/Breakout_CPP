#include "Ball.h"


Ball::Ball(float size, int nbBall)
{
	ballSize = size;
	NumberBall = nbBall;

	InitializeBall();
	
}

Ball::~Ball()
{
}

/// <summary>
/// Initialize ball value
/// </summary>
void Ball::InitializeBall()
{
	ball_shape.setRadius(ballSize);
	Constants::BallPositionRatio(this, 0.5, 1);
	Constants::BallOriginByRatio(this, 0.5, 1);
	SetBallColor(sf::Color::White);
}

sf::Vector2f Ball::GetDirection()
{
	return direction;
}

/// <summary>
/// Get the shape
/// </summary>
/// <returns></returns>
sf::CircleShape Ball::GetShape()
{
	return ball_shape;
}

/// <summary>
/// Get the bounding box (collision box) of the ball shape
/// </summary>
/// <returns> Ball bounding box </returns>
sf::FloatRect Ball::GetBallBoundingBox()
{
	return ball_shape.getGlobalBounds();
}


float Ball::GetBallXPosition()
{
	return ball_posX;
}
float Ball::GetBallYPosition()
{
	return ball_posY;
}
float Ball::GetBallSize()
{
	return ballSize;
}

bool Ball::GetChangeDirection()
{
	return ChangeDirection;
}

std::list<Brick*> Ball::GetCollisionBrickList()
{
	return CollisionBrickList;
}

int Ball::GetNumberBall()
{
	return NumberBall;
}

void Ball::AddBrick(Brick* brick)
{
	CollisionBrickList.push_back(brick);
}

void Ball::ResetCollisionBrickList()
{
	CollisionBrickList.clear();
}

/// <summary>
/// Set ball color
/// </summary>
/// <param name="color"> Color to set the ball color </param>
void Ball::SetBallColor(sf::Color color)
{
	ball_shape.setFillColor(color);
}

void Ball::SetChangeDirection(bool boool)
{
	ChangeDirection = boool;
	
}

void Ball::SetDirection(float x, float y)
{
	direction.x = x;
	direction.y = y;
	Math::Normalize(direction);
}

void Ball::XOppositeDirection()
{
	direction.x = -direction.x;
}

void Ball::YOppositeDirection()
{
	direction.y = -direction.y;	
}

/// <summary>
/// Set the ball shape origin
/// </summary>
/// <param name="x"> Origin point on X axis </param>
/// <param name="y"> Origin point on Y axis </param>
void Ball::SetBallOrigin(float x, float y)
{
	ball_shape.setOrigin(x, y);
}

/// <summary>
/// Set the ball position
/// </summary>
/// <param name="x"> Ball position on X axis </param>
/// <param name="y"> Ball position on Y axis </param>
void Ball::SetBallPosition(float x, float y)
{
	ball_posX = x;
	ball_posY = y;
	ball_shape.setPosition(ball_posX, ball_posY);
}