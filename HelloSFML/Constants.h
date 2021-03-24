#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Brick.h"

static class Constants
{
public:
	 static const int screenWidth = 600	;
	 static const int screenHeight = 900 ;
public:
	static void BallOriginByRatio(Ball* ball, float ratioX, float ratioY);
	static void BallPositionRatio(Ball* ball, float width, float height);

	static void BrickPositionRatio(Brick* brick, float width, float height);
};
