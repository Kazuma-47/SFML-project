#include "ScoreManager.h"
#include <iostream>

ScoreManager::ScoreManager(float pointValue, const std::string& fontFilePath)
{
	if (!textFont.loadFromFile(fontFilePath)){
		std::cerr <<"font not found for score UI";
	}
	scoreUI.setPosition(10.0f, 10.0f);
	scoreUI.setFont(textFont);
	scoreUI.setCharacterSize(20);
	scoreUI.setFillColor(sf::Color::White); 
	scoreUI.setString("Score: 0");
	
	score = 0;
	points = pointValue;
}

void ScoreManager::SetPoints(float pointValue) {
	points = pointValue;
}

void ScoreManager::AddPoints() {
	score += points;
	scoreUI.setString("Score: " + std::to_string(static_cast<int>(score)));
}

void ScoreManager::Draw(sf::RenderWindow& window) const {
	window.draw(scoreUI);
}

float ScoreManager::GetScore()const {
	return score;
}
