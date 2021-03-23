#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"

static class Constants
{
public:
	 static const int screenWidth = 1280	;
	 static const int screenHeight = 720;
public:
	static void BallOriginByRatio(Ball* ball, float ratioX, float ratioY);
	static void BallPositionRatio(Ball* ball, float width, float height);
};
