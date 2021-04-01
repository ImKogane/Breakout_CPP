#include "GameManager.h"


GameManager::GameManager()
{
	gm_score = 0;
}

void GameManager::AddScore(int newScore)
{
	gm_score += newScore;
}

int GameManager::GetScore()
{
	return gm_score;
}