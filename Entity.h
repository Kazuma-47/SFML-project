#pragma once
#include "Vector2.h"
#include <SFML/Graphics.hpp>

class Entity
{
	private:
		Vector2 position;
		sf::Sprite sprite;
		sf::Texture texture;
		float stepSize;
		
	public:
		Entity(std::string textureFilePath, Vector2 startPosition , float movementSpeed);
		sf::Sprite& GetSprite();
		void SetSpriteScale(float scale);
		void SetPosition(Vector2 newPos);
		float GetEntitySpeed();
		void Move(Vector2 step, float deltaTime);
};

