#pragma once
class GameManager
{
private:
	//Score system
	int gm_score;

public :
	GameManager();

	//Score system
	void AddScore(int newScore);
	int GetScore();
};

