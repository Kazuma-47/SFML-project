#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
class ScoreManager
{
	private:
		float score;
		float points;
		sf::Text scoreUI;
		sf::Font textFont;

	public:
		ScoreManager(float pointValue, const sf::Font& font);
		void SetPoints(float pointValue);
		void AddPoints();
		int GetScore()const;
		void Draw(sf::RenderWindow& window)const;
};