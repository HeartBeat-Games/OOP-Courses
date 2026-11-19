#pragma once
#include "Entity.h"

class Enemy : public Entity
{
private:
	virtual Vector2 getDirection(Entity*) = 0;

public:
	Enemy(const Vector2& position)
		: Entity(position, E_CharacterType::Enemy) { m_symbol = 'X'; }

	// Entity override
	virtual void onUpdate(Map& currentMap, std::vector<Entity*>& allEntities) override;
};