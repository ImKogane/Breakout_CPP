#include "Canon.h"


Canon::Canon(float posRatioX, float posRatioY, float sizeX, float sizeY)
{
	canon_shape = sf::RectangleShape(sf::Vector2f(sizeX, sizeY));
	canon_shape.setFillColor(sf::Color::White);

	canon_sizeX = sizeX;
	canon_sizeY = sizeY;
	SpawnCanonByRatio(posRatioX, posRatioY);
}

void Canon::SpawnCanonByRatio(float ratioX, float ratioY)
{
	canon_posX = Constants::screenWidth * ratioX;
	canon_posY = Constants::screenHeight * ratioY;
	SetCanonOriginByRatio(0.5f, 0.5f);
	SetCanonPosition(canon_posX, canon_posY);
}

void Canon::SetCanonPosition(float X, float Y)
{
	canon_shape.setPosition(X, Y);
}

void Canon::SetCanonOriginByRatio(float ratioX, float ratioY)
{
	canon_shape.setOrigin(canon_sizeX * ratioX, canon_sizeY * ratioY);
}

sf::RectangleShape Canon::GetCanonShape()
{
	return canon_shape;
}