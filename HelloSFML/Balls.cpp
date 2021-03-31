#include "Balls.h"

Balls::Balls(int size)
{
	BallsSize = size;
	
}

int Balls::GetBallsSize()
{
	return BallsSize;
}

std::list<Ball*> Balls::GetBallList()
{
	return BallList;
}

int Balls::GetCurrentBallCount()
{
	return countBall;
}

Ball* Balls::AddBall()
{
	Ball* ball = new Ball(10, countBall);
	BallList.push_back( ball);
	countBall++;
	return ball;
}

void Balls::RemoveBall(Ball* ball)
{
	countBall--;
}
