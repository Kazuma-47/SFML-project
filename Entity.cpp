#include "Entity.h"

/// <summary>
/// neemt de locatie van de texture voor de sprite van het object en de start locatie en 
/// zorgd ervoor dat hij op de juiste plek begind en met de juiste texture word gebruikt
/// </summary>
/// <param name="textureFilePath">het pad voor de texture</param>
/// <param name="startPosition">locatie waar het object spawned</param>
Entity::Entity(std::string textureFilePath, Vector2 startPosition , float movementSpeed)
{
    texture.loadFromFile(textureFilePath);
    sprite.setTexture(texture);
    stepSize = movementSpeed;
    position  = startPosition;
    SetPosition(startPosition);
}

void Entity::SetSpriteScale(float scale) {
    sprite.setScale(scale, scale);
}

sf::Sprite& Entity::GetSprite() {
    return sprite;
}

void Entity::AddForce(Vector2 force) {
    velocity = velocity + force;
}

void Entity::SetPosition(Vector2 newPos) 
{
    position = newPos;
    sprite.setPosition(position.x, position.y);
}

Vector2 Entity::GetPosition()
{
    return position;
}

float Entity::GetEntitySpeed() {
    return stepSize;
}

/// <summary>
/// voegd een force toe wanneer de speler een input doet en verlaag het langzamerhand met frictie 
/// </summary>
/// <param name="step">hoeveel force er per frame bij komt</param>
/// <param name="deltaTime">zorgd ervoor dat de movement los van de fps word gedaan.</param>
void Entity::Move(Vector2 step, float deltaTime) {
    AddForce(step);
    float friction = 0.99f;
    velocity = velocity * friction;

    if (std::abs(velocity.x) < 0.01f) velocity.x = 0.0f;
    if (std::abs(velocity.y) < 0.01f) velocity.y = 0.0f;

    Vector2 scaledVelocity = velocity * deltaTime;
    Vector2 newPosition = scaledVelocity + position;

    // Keep within bounds (assuming screen size is 800x900)
    float spriteWidth = sprite.getGlobalBounds().width;
    float spriteHeight = sprite.getGlobalBounds().height;

    // Manually enforce boundaries using std::min and std::max
    newPosition.x = std::max(0.0f, std::min(newPosition.x, 800.0f - spriteWidth));

    SetPosition(newPosition);
    sprite.setPosition(newPosition.x, newPosition.y);
}




