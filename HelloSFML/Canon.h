#include <SFML/Graphics.hpp>
#include "Constants.h"
#include <iostream>

#pragma once
class Canon
{
private :
	//float canon_shootSpeed;
	sf::RectangleShape canon_shape;
	float canon_sizeX;
	float canon_sizeY;
	float canon_posX;
	float canon_posY;

public :
	Canon(float posRatioX, float posRatioY, float sizeX, float sizeY);
	void SpawnCanonByRatio(float ratioX, float ratioY);
	void SetCanonPosition(float newPosX, float newPosY);
	void SetCanonOriginByRatio(float ratioX, float ratioY);

	sf::RectangleShape GetCanonShape();
};

