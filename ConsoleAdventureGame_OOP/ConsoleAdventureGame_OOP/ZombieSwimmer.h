#pragma once
#include "Zombie.h"
#include "Swimmer.h"

class ZombieSwimmer : public Zombie, public Swimmer
{
public:
	ZombieSwimmer(const Vector2& position);

	// Entity override
	void onUpdate(Map& currentMap, std::vector<Entity*>& allEntities) override;
};

