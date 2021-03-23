#include "Ball.h"


Ball::Ball(float size, float x, float y)
{
	sf::CircleShape ball(size);
	ball.setPosition(ballPosX, ballPosY);
}