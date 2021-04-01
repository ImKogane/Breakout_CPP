#include "ScoreManager.h"


ScoreManager::ScoreManager()
{
	sm_score = 0;
}

void ScoreManager::AddScore(int newScore)
{
	sm_score += newScore;
}

int ScoreManager::GetScore()
{
	return sm_score;
}