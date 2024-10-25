#pragma once
#include "Obstacle.h"

#include <vector>

#define OM ObstacleManager::Instance()

class ObstacleManager
{
private:

	std::vector<Obstacle*> obstacles;

	ObstacleManager() = default;
	~ObstacleManager();
	ObstacleManager(const ObstacleManager&) = delete;
	ObstacleManager& operator =(const ObstacleManager&) = delete;

public:

	inline static ObstacleManager& Instance()
	{
		static ObstacleManager manager;
		return manager;
	}

	inline std::vector<Obstacle*> GetObstacles() { return obstacles; }
	inline void AddObstacles(Obstacle* _obstacles) { obstacles.push_back(_obstacles); }
};



