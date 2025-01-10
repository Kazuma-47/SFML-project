#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Vector2.h"
#include "WaveSpawner.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 900), "Racing Game");

    Entity player(".\\Assets\\SpaceShip.png", Vector2(350.0f, 750.0f), 500.0f);
    player.SetSpriteScale(0.05f);

    WaveSpawner spawner(3, 5, 800, 10); 

    Vector2 playerInput;
    sf::Clock clock;

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();
 
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        #pragma region  Player Movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            playerInput = Vector2(-player.GetEntitySpeed(), 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            playerInput = Vector2(player.GetEntitySpeed(), 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            playerInput = Vector2(0, -player.GetEntitySpeed());
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            playerInput = Vector2(0, player.GetEntitySpeed());
        }
        else {
            playerInput = Vector2::VectorZero();
        }
        #pragma endregion

        #pragma region  Updates
        player.Move(playerInput, deltaTime);

        spawner.Update(deltaTime);
        for (Obstacle& obstacle : spawner.GetObjects()) {
            obstacle.Update(deltaTime);
        }
        #pragma endregion

        #pragma region  Render
        window.clear();

        window.draw(player.GetSprite());

        for (auto& obstacle : spawner.GetObjects()) {
            window.draw(obstacle.GetSprite());
        }

        window.display();
        #pragma endregion
    }

    return 0;
}
