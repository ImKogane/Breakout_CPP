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
	std::list<Brick*> GenerateLevel();
	float DefineBrickXSize(int BricksCountInLine);
};
