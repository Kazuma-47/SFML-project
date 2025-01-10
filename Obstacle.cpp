#pragma once
#include "Obstacle.h"
#include "Entity.h"
#include "Vector2.h"

void Obstacle::Update(float deltaTime)
{
	Move(Vector2::VectorUp() , deltaTime);
}
