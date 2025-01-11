#include "WaveSpawner.h"
#include "Entity.h"
#include "Vector2.h"
#include <cstdlib> 
#include <random>
#include <iostream>

/// <summary>
/// set the timer door een nummer neemt binnen de minTimerValue en de maxTimerValue en gebruikt dat om objecten met een interval te spawnen
/// </summary>
/// <param name="minTimerValue">minimale value voor de timer</param>
/// <param name="maxTimerValue">maximale value voor de timer</param>
/// <param name="screenWidth">neemt de maximale breedte van je scherm voor het spawnen</param>
/// <param name="objectAmmount">bepaald de moeilijkheid door meer objecten te spawnen die tegelijk naar beneden vallen in je scherm met een interval </param>
WaveSpawner::WaveSpawner(int minTimerValue, int maxTimerValue , int screenWidth , int objectAmmount)
{
	this->screenWidth = screenWidth;
	minTimer = minTimerValue;
	maxTimer = maxTimerValue;
	spawnInterval = GetRandom(minTimer, maxTimer);
	this->objectAmmount = objectAmmount;

	SpawnObstacle();
}

void WaveSpawner::Update(float deltaTime) {
	currentTimer += deltaTime; 
	if (currentTimer >= spawnInterval && currentObjectCount < objectAmmount) {
		SpawnObstacle();
	}
}

void WaveSpawner::SpawnObstacle()
{
	while (currentObjectCount != objectAmmount) {
		int randomLocation = GetRandom(40, screenWidth);	 
		Obstacle object(".\\Assets\\Asteroid.png", Vector2(randomLocation, -50.0f), 100.0f);
		object.SetSpriteScale(0.05f);
	
		objects.push_back(object);
		currentObjectCount++;
		currentTimer = 0;
	}
}

void WaveSpawner::SetTimerValue(int minTimerValue, int maxTimerValue)
{
	minTimer = minTimerValue;
	maxTimer = maxTimerValue;
	spawnInterval = GetRandom(minTimer, maxTimer);
}

int WaveSpawner::GetRandom(int minTimerValue, int maxTimerValue) 
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(minTimerValue, maxTimerValue);
	return dist(gen);
}

std::vector<Obstacle>& WaveSpawner::GetObjects() {
	return objects;
}



