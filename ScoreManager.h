#pragma once
class ScoreManager
{
private:
	float score;
	float points;
public:
	ScoreManager(float pointValue);
	void SetPoints(float pointValue);
	void AddPoints();
	float GetScore()const;
};

