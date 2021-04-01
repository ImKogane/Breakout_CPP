#include <list>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"

#pragma once
class Balls
{
private:
	int BallsSize;
	std::list<Ball*> BallList;
	int countBall;

public: 
	
	Balls(int size);

	//getter
	int GetBallsSize();
	std::list<Ball*>& GetBallList();
	int GetCurrentBallCount();

	Ball* AddBall();
	void RemoveBall();
};

