#pragma once
#include <SFML/Graphics.hpp>

class ScoreManager
{
	private:
		float score;
		float points;
		sf::Text scoreUI;
		sf::Font textFont;

	public:
		ScoreManager(float pointValue, const std::string& fontFilePath);
		void SetPoints(float pointValue);
		void AddPoints();
		float GetScore()const;
		void Draw(sf::RenderWindow& window)const;
};