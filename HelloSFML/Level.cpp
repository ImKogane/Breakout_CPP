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

std::list<Brick*> Level::GetBrickList()
{
	return levelBrickList;
}

std::list<Brick*> Level::GenerateLevel()
{
	levelBrickList.clear();
	for (size_t i = 0; i < levelBrickInLines; i++)
	{ 
		for (size_t j = 0; j < levelBrickLines; j++)
		{

			Brick* tempBrick = new Brick(Constants::screenWidth/(1.1*levelBrickInLines), 30);
			levelBrickList.push_back(tempBrick);
			tempBrick->SetBrickPosition((Constants::screenWidth / (levelBrickInLines ) )* i+5, 40 * j+5);
			tempBrick->SetBrickColor();
		}
	}

	return levelBrickList;
}

void Level::RefreshLevel(sf::RenderWindow window)
{
	for (Brick* brick : levelBrickList)
	{
		window.draw(brick->GetBrickShape());
	}
	
}



float Level::DefineBrickXSize(int BricksCountInLine)
{
	float size = Constants::screenWidth / BricksCountInLine;
	return size;
}
