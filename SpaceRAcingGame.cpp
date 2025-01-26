#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Vector2.h"
#include "WaveSpawner.h"
#include "ScoreManager.h"
#include "Background.h"
#include "Obstacle.h"

int main()
{
    //Initialize het spel
    #pragma region Initialization
    sf::RenderWindow window(sf::VideoMode(800, 900), "Asteroid Rains");
    Entity player(".\\Assets\\SpaceShip.png", Vector2(350.0f, 750.0f), 10.0f);
    player.SetSpriteScale(0.05f);
    sf::Font gamefont;
    gamefont.loadFromFile(".\\Assets\\fonts\\Roboto-VariableFont_wdth,wght.ttf");

    ScoreManager scoreManager = ScoreManager(10, gamefont);
    WaveSpawner spawner(2, 4, 800, 5);
    Background background(window, ".\\Assets\\background.jpg");
    Vector2 playerInput;
    sf::Clock clock;
    bool gameOver = false;
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
        if (!gameOver)
        {
            #pragma region  Player Movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                playerInput = Vector2(-player.GetEntitySpeed(), 0);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                playerInput = Vector2(player.GetEntitySpeed(), 0);
            }
            else {
                playerInput = Vector2::VectorZero();
            }
            #pragma endregion

            //update objecten maar word elke frame aangeroepen
            #pragma region  Updates
            std::vector<Obstacle>& obstacles = spawner.GetObjects();
            for (std::vector<Obstacle>::iterator object = obstacles.begin(); object != obstacles.end();)
            {
                if (object->IsOutOfBounds(900))
                {
                    scoreManager.AddPoints();
                    object = obstacles.erase(object);
                }
                else
                {
                    object->Update(window, deltaTime);
                    if (object->CheckCollision(player))
                        gameOver = true;

                    ++object;
                }
            }

            player.Move(playerInput, deltaTime);
            spawner.Update(deltaTime);
            #pragma endregion

            //render alles dat op het scherm.
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
        else    //Als het spel voorbij is
        {
            sf::Text gameOverText("Game Over! Score is: " + std::to_string(scoreManager.GetScore()), gamefont, 30);
            gameOverText.setFillColor(sf::Color::White);
            gameOverText.setPosition(300, 450);
            window.clear();
            window.draw(gameOverText);
            window.display();
        } 
    }
    return 0;
}
