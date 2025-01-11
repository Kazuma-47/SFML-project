#include "ScoreManager.h"

ScoreManager::ScoreManager(float pointValue)
{
	score = 0;
	points = pointValue;
}

void ScoreManager::SetPoints(float pointValue) {
	points = pointValue;
}

void ScoreManager::AddPoints() {
	score += points;
}
float ScoreManager::GetScore()const {
	return score;
}
