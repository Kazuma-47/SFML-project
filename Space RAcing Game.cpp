#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Vector2.h"
#include "WaveSpawner.h"
#include "ScoreManager.h"
#include "Background.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 900), "Asteroid Rains");

    #pragma region Initialization
    Entity player(".\\Assets\\SpaceShip.png", Vector2(350.0f, 750.0f), 500.0f);
    player.SetSpriteScale(0.05f);

    ScoreManager scoreManager = ScoreManager(10, ".\\Assets\\fonts\\Roboto-VariableFont_wdth,wght.ttf");
    WaveSpawner spawner(2, 4, 800, 5); 
    Background background( window, ".\\Assets\\background.jpg");
    Vector2 playerInput;
    sf::Clock clock;
    #pragma endregion

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        static float fixedTimer = 0.0f;

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

        //update objecten maar word elke frame aangeroepen
        #pragma region  Updates
        for (Obstacle& obstacle : spawner.GetObjects()) 
        {
            obstacle.Update(deltaTime);
            if (obstacle.CheckCollision(player)) {
                std::cout << "Collision occurred!" << std::endl;
                // Handle the collision (e.g., stop the game, reduce health, etc.)
            }
        }
        player.Move(playerInput, deltaTime);
        spawner.Update(deltaTime);

        #pragma endregion
        //Update maar word ipv elke frame elke seconde aangeroepen
        #pragma region FixedUpdate
        fixedTimer += deltaTime;
        if (fixedTimer >= 1.0f) {
            scoreManager.AddPoints();
            fixedTimer = 0.0f;
        }
        #pragma endregion

        //render alle objecten die op het scherm zichtbaar moet en zijn
        #pragma region  Render
        window.clear();
        background.DrawBackground(window);
        window.draw(player.GetSprite());
        scoreManager.Draw(window);

        for (auto& obstacle : spawner.GetObjects()) {
            window.draw(obstacle.GetSprite());
        }
        window.display();
        #pragma endregion
    }
    return 0;
}
