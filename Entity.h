#pragma once
#include "Vector2.h"
#include <SFML/Graphics.hpp>

class Entity
{
	private:
		Vector2 position;
		Vector2 velocity;
		sf::Sprite sprite;
		sf::Texture texture;
		float stepSize;
		
	public:
		Entity(std::string textureFilePath, Vector2 startPosition , float movementSpeed);
		sf::Sprite& GetSprite();
		void AddForce(Vector2 force);
		void SetSpriteScale(float scale);
		void SetPosition(Vector2 newPos);
		Vector2 GetPosition();
		float GetEntitySpeed();
		void Move(Vector2 step, float deltaTime);
};

