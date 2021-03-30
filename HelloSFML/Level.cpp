#include "Level.h"

Level::Level(int linesCount, int brickInLines)
{
	levelBrickLines = linesCount;
	levelBrickInLines = brickInLines;
}

int Level::GetLineCount()
{
	return levelBrickLines;
}

int Level::GetBrickInLines()
{
	return levelBrickInLines;
}

std::list<Brick*> Level::GenerateLevel()
{
	levelBrickList.clear();
	for (size_t i = 0; i < levelBrickLines; i++)
	{ 
		for (size_t j = 0; j < levelBrickInLines; j++)
		{
			Brick* tempBrick = new Brick(10, 10);
			levelBrickList.push_back(tempBrick);
		}
	}

	return levelBrickList;
}

float Level::DefineBrickXSize(int BricksCountInLine)
{
	float size = Constants::screenWidth / BricksCountInLine;
	return size;
}
