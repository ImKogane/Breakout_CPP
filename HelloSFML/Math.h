#pragma once
#include "Brick.h"
#include <list>
#include <SFML/Graphics.hpp>

class Math
{
public:
	static void Normalize(sf::Vector2f &V);
	static bool ContainsBrick(const std::list<Brick*>& list, Brick* x);
};

