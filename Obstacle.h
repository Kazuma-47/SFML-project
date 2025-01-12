#pragma once
#include "Vector2.h"
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Obstacle : public Entity
{
	public:
		Obstacle(std::string textureFilePath, Vector2 startPosition, float movementSpeed) : Entity(textureFilePath, startPosition, movementSpeed) {};
		bool CheckCollision(Entity& player);
		void Update(float deltaTime);
};

