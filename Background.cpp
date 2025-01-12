#include "Background.h"

Background::Background(sf::RenderWindow& window, std::string textureFilePath)
{
	backgroundTexture.loadFromFile(textureFilePath);
	backgroundSprite.setTexture(backgroundTexture);

	backgroundSprite.setScale(
		static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x,
		static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y
	);
}

void Background::DrawBackground(sf::RenderWindow& window) {
	window.draw(backgroundSprite);
}