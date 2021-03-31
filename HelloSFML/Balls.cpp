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
	return BallList.size();
}

Ball* Balls::AddBall()
{
	Ball* ball = new Ball(10);
	BallList.push_back(ball);
	return ball;
}

void Balls::RemoveBall(Ball* ball)
{
	ball->~Ball();
}
