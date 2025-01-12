#pragma once
#include <SFML/Graphics.hpp>

class Background
{	
	private:
		sf::Sprite backgroundSprite;
		sf::Texture backgroundTexture;
	public:
		Background(sf::RenderWindow& window, std::string textureFilePath);
		void DrawBackground(sf::RenderWindow& window);
};

