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

void Entity::SetPosition(Vector2 newPos) 
{
    position = newPos;
    sprite.setPosition(position.x, position.y);
}

float Entity::GetEntitySpeed() {
    return stepSize;
}

void Entity::Move(Vector2 step, float deltaTime)
{
    Vector2 scaledStep = step * deltaTime; 
    SetPosition(scaledStep + position);
    sprite.move(scaledStep.x, scaledStep.y);
}

