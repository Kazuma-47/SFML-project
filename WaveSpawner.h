#pragma once
#include "Vector2.h"
#include "Entity.h"
#include "Obstacle.h"
#include <cstdlib> 
#include <random>
#include <iostream>
class WaveSpawner
{
	private:
		int spawnInterval;
		int objectAmmount,
			currentObjectCount = 0;
		std::vector<Obstacle> objects;
		int minTimer,
			maxTimer;
		float currentTimer;
		int screenWidth;

public:
		WaveSpawner(int minTimerValue, int maxTimerValue, int screenWidth ,int objectAmmount);
		void SpawnObstacle();
		void SetTimerValue(int minTimerValue, int maxTimerValue);
		int GetRandom(int minTimerValue, int maxTimerValue);
		std::vector<Obstacle>& GetObjects();
		void Update(float deltaTime);
		void RemoveObject(size_t index);
};

