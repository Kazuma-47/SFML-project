#pragma once
#include "Vector2.h"
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Obstacle : public Entity
{
	private:
		
	public:
		Obstacle(std::string textureFilePath, Vector2 startPosition, float movementSpeed) : Entity(textureFilePath, startPosition, movementSpeed) {};
		void Update(float deltaTime);
};

