#include <list>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"

#pragma once
class Balls
{
private:
	int BallsSize;
	int BallsDamage;
	std::list<Ball*> BallList;
	int countBall;

public: 
	
	Balls(int size, int damage);

	//getter
	int GetBallsSize();
	int GetBallsDamage();
	std::list<Ball*>& GetBallList();
	int GetCurrentBallCount();

	Ball* AddBall();
	void RemoveBall();
};

