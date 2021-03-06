#include <list>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Brick.h"
#include "Constants.h"


#pragma once
class Level
{
private:
	int levelBrickLines;
	int levelBrickInLines;
	std::list<Brick*> levelBrickList;

public:
	Level(int linesCount, int brickInLines);
	int GetLineCount();
	int GetBrickInLines();
	std::list<Brick*> GetBrickList();
	std::list<Brick*> GenerateLevel();
	void RefreshLevel(sf::RenderWindow window);
	float DefineBrickXSize(int BricksCountInLine);
};
