#pragma once
#include <SFML/Graphics.hpp>

class Ball;
class Brick;
static class Constants
{

public:
	 static const int screenWidth = 720	;
	 static const int screenHeight = 900 ;
public:
	static void BallOriginByRatio(Ball* ball, float ratioX, float ratioY);
	static void BallPositionRatio(Ball* ball, float width, float height);

	static void BrickPositionRatio(Brick* brick, float width, float height);
};
