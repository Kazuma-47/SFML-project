#include "Obstacle.h"
#include "Entity.h"
#include "Vector2.h"

void Obstacle::Update(float deltaTime)
{
	Move(Vector2(0.0f, 200.0f), deltaTime);
}

bool Obstacle::CheckCollision(Entity& player)
{
    sf::FloatRect obstacleBounds = GetSprite().getGlobalBounds();
    sf::FloatRect playerBounds = player.GetSprite().getGlobalBounds();

    return obstacleBounds.intersects(playerBounds);
}
