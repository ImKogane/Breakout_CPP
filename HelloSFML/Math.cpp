#include "Math.h"
#include <SFML/Graphics.hpp>
#include <iostream>


void Math::normalize(sf::Vector2f &V)
{
	float length = sqrt(V.x * V.x + V.y * V.y);
	V.x = V.x / length;
	V.y = V.y / length;
}
