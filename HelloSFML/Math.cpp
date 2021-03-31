#include "Math.h"

#include <iostream>


void Math::Normalize(sf::Vector2f &V)
{
	float length = sqrt(V.x * V.x + V.y * V.y);
	V.x = V.x / length;
	V.y = V.y / length;
}

bool Math::ContainsBrick(std::list<Brick*> list, Brick* x)
{
	return std::find(list.begin(), list.end(), x) != list.end();
}
