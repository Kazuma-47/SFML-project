#include "WaveSpawner.h"

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
	SetTimerValue(minTimerValue, maxTimerValue);
	this->objectAmmount = objectAmmount;

	SpawnObstacle();
}

/// <summary>
/// behandel wat er elke frame moet gebeuren om de wavespawner werkend te houden
/// </summary>
void WaveSpawner::Update(float deltaTime) {
	currentTimer += deltaTime; 
	if (currentTimer >= spawnInterval) 
	{
		SpawnObstacle();
		SetTimerValue(minTimer, maxTimer);
	}
}

void WaveSpawner::RemoveObject(size_t index)
{
	if (index < objects.size()) {
		objects[index].~Obstacle();

		objects.erase(objects.begin() + index);
	}
}

void WaveSpawner::SpawnObstacle()
{
	for (int i = currentObjectCount; i < objectAmmount; ++i) {
		float randomLocation = GetRandom(40, screenWidth);
		float randomSPeed = GetRandom(4, 9);
		Obstacle object(".\\Assets\\Asteroid.png", Vector2(randomLocation, -50.0f), randomSPeed);
		object.SetSpriteScale(0.05f);
		objects.push_back(object);
	}
}

/// <summary>
/// zet de timer van de volgende wave maar word ook gebruikt om te resettten 
/// </summary>
/// <param name="minTimerValue">minimale value voor de timer</param>
/// <param name="maxTimerValue">maximale value voor de timer</param>
void WaveSpawner::SetTimerValue(int minTimerValue, int maxTimerValue)
{
	minTimer = minTimerValue;
	maxTimer = maxTimerValue;
	spawnInterval = GetRandom(minTimer, maxTimer);
	currentTimer = 0;
	currentObjectCount = 0;
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



