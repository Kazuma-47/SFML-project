#include "Obstacle.h"

void Obstacle::Update(sf::RenderWindow& window, float deltaTime) 
{
	Move(Vector2(direction, GetEntitySpeed()), deltaTime);
    sf::FloatRect obstacleBounds = GetSprite().getGlobalBounds();

    if (obstacleBounds.left <= 0) {
        FlipDirection();
    }
    else if (obstacleBounds.left + obstacleBounds.width >= window.getSize().x) {
        FlipDirection();
    }
}

bool Obstacle::IsOutOfBounds(float screenHeight) {
    return (GetPosition().y > screenHeight);
}

void Obstacle::GetRandomDirection() {
    direction = (rand() % 2 == 0) ? -1.0f : 1.0f;
}


bool Obstacle::CheckCollision(Entity& player)
{
    Vector2 obstaclePos = GetPosition();
    Vector2 playerPos = player.GetPosition();

    float obstacleRadius = std::min(GetSprite().getGlobalBounds().width, GetSprite().getGlobalBounds().height) / 2.0f;
    float playerRadius = std::min(player.GetSprite().getGlobalBounds().width, player.GetSprite().getGlobalBounds().height) / 2.0f;

    float distance = std::sqrt(std::pow(playerPos.x - obstaclePos.x, 2) + std::pow(playerPos.y - obstaclePos.y, 2));

    return distance < (obstacleRadius + playerRadius);
}

void Obstacle::FlipDirection() {
    direction = -direction;
}
