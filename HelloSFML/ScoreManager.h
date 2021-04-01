#pragma once
class ScoreManager
{
private:
	//Score system
	int sm_score;

public :
	ScoreManager();

	//Score system
	void AddScore(int newScore);
	int GetScore();
};

