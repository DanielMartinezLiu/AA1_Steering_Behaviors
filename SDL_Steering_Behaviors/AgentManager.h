#pragma once
#include "Agent.h"

#include <vector>

#define AM AgentManager::Instance()

class AgentManager
{
private:

	std::vector<Agent*> agents;

	AgentManager() = default;
	~AgentManager();
	AgentManager(const AgentManager&) = delete;
	AgentManager& operator =(const AgentManager&) = delete;

public:

	inline static AgentManager& Instance()
	{
		static AgentManager manager;
		return manager;
	}

	inline std::vector<Agent*> GetAgents() { return agents; }
	inline void SetAgents(std::vector<Agent*> _agents) { agents = _agents; }
};

