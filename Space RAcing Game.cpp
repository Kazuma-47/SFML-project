#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Vector2.h"
#include "WaveSpawner.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 900), "Racing game");

    Entity player(".\\Assets\\SpaceShip.png", Vector2(350.0f, 750.0f) , 200.0f);
    player.SetSpriteScale(0.050f);
    player.SetPosition(player.GetPosition());
    WaveSpawner spawner = WaveSpawner(1, 3, 800, 10);
   
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

        #pragma region Player movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            playerInput = Vector2( - player.GetEntitySpeed(), 0);
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
        else if (sf::Event::KeyReleased) {
            playerInput = Vector2::VectorZero();
        }
        #pragma endregion

        for (Obstacle& obstacle : spawner.GetObjects()) {
            window.draw(obstacle.GetSprite());
            obstacle.Update(deltaTime);
        }

        player.Move(playerInput , deltaTime);
      
        window.clear();
        window.draw(player.GetSprite());
        window.display();
    }
    return 0;
}




