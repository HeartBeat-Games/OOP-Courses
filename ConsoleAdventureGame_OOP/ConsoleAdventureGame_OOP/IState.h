#pragma once
#include "Map.h"
#include "Entity.h"
#include <vector>

class IState
{
public:
	virtual ~IState() {};

	virtual void onEnter(Entity* player) = 0;
	virtual int onUpdate(Map& currentMap, Entity* player, std::vector<Entity*> allEntities) = 0;
	virtual void onExit(Entity* player) = 0;
};