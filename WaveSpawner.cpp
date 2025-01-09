#pragma once
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
	spawnInterval = GetRandomInterval(minTimer, maxTimer);
	this->objectAmmount = objectAmmount;

	SpawnObstacle();
}

void WaveSpawner::SpawnObstacle()
{
	while (currentObjectCount != objectAmmount) {
		int randomLocation = GetRandomInterval(40, screenWidth);	 
		Obstacle object(".\\Assets\\Asteroid.png", Vector2((randomLocation, 0)), 0.0f);
	
		objects.push_back(object);
		currentObjectCount++;
	}
}

void WaveSpawner::SetTimerValue(int minTimerValue, int maxTimerValue)
{
	minTimer = minTimerValue;
	maxTimer = maxTimerValue;
	spawnInterval = GetRandomInterval(minTimer, maxTimer);
}

int WaveSpawner::GetRandomInterval(int minTimerValue, int maxTimerValue) 
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(minTimerValue, maxTimerValue);
	return dist(gen);
}

std::vector<Obstacle>& WaveSpawner::GetObjects() {
	return objects;
}



