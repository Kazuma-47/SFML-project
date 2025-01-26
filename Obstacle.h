#pragma once
#include "Vector2.h"
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <random>
#include<iostream>

class Obstacle : public Entity
{
	private:
		float direction = 1.0f;
	public:
		Obstacle(std::string textureFilePath, Vector2 startPosition, float movementSpeed) : Entity(textureFilePath, startPosition, movementSpeed) {
			GetRandomDirection();
		};
		bool CheckCollision(Entity& player);
		bool IsOutOfBounds(float screenHeight);
		void FlipDirection();
		void Update(sf::RenderWindow& window, float deltaTime);
		void GetRandomDirection();
};

