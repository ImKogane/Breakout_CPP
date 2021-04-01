#include "Balls.h"

Balls::Balls(int size, int damage)
{
	BallsSize = size;
	BallsDamage = damage;
	
}

int Balls::GetBallsSize()
{
	return BallsSize;
}

int Balls::GetBallsDamage()
{
	return BallsDamage;
}

std::list<Ball*>&  Balls::GetBallList()
{
	return BallList;
}

int Balls::GetCurrentBallCount()
{
	return countBall;
}

Ball* Balls::AddBall()
{
	Ball* ball = new Ball(10, countBall, BallsDamage);
	BallList.push_back( ball);
	countBall++;
	return ball;
}

void Balls::RemoveBall()
{
	countBall--;
}
