#include "Constants.h"
#include <SFML/Graphics.hpp>
#include <iostream>


void Constants::BallOriginByRatio(Ball* ball, float ratioX, float ratioY)
{
	ball->SetBallOrigin((ball->GetBallSize() * 2) * ratioX, (ball->GetBallSize() * 2) * ratioY);
}

void Constants::BallPositionRatio(Ball* ball, float ratioX, float ratioY)
{
	ball->SetBallPosition(Constants::screenWidth * ratioX, Constants::screenHeight * ratioY);
}
